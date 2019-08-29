#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Person{
    char name[21];
    char time[12];
    int on_off;  // on -> 0, off -> 1
}customer[1000];

int toll[25];

bool cmp(Person a, Person b){
    if(strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) < 0;
    else return strcmp(a.time, b.time) < 0;
}

double cal_cost_total(char* time){
    int MM, dd, hh, mm;
    sscanf(time, "%d:%d:%d:%d", &MM, &dd, &hh, &mm);
    int total = 0;
    for(int i=0; i<24; i++){
        total += toll[i]*60;
    }
    total *= dd;
    total += toll[hh]*mm;
    for(int i=0; i<hh; i++){
        total += toll[i]*60;
    }
    return total / 100.0;
}

double cal_cost(char* on_time, char* off_time){
    return cal_cost_total(off_time) - cal_cost_total(on_time);
}

int cal_time(char* on_time, char* off_time){
    int MM, dd, hh, mm;
    sscanf(on_time, "%d:%d:%d:%d", &MM, &dd, &hh, &mm);
    int total_min = dd*60*24 + hh*60 + mm;
    sscanf(off_time, "%d:%d:%d:%d", &MM, &dd, &hh, &mm);
    total_min = dd*60*24 + hh*60 + mm - total_min;
    return total_min;
}

int main(){
    for(int i=0; i<24; i++){
        scanf("%d", &toll[i]);
    }
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        char line_status[9];
        scanf("%s %s %s", customer[i].name, customer[i].time, line_status);
        if(strcmp(line_status, "on-line") == 0) customer[i].on_off = 0;
        else customer[i].on_off = 1;
    }
    sort(customer, customer+N, cmp);
    int head = 0, tail = 0;
    while(tail < N){
        while(strcmp(customer[tail].name, customer[head].name) == 0) tail += 1;
        int circle_flag = 0;
        for(int j=head; j<tail-1; j++){
            if(customer[j].on_off == 0 && customer[j+1].on_off == 1){
                circle_flag = 1;
                break;
            }
        }
        if(circle_flag == 1){
            printf("%s %c%c\n", customer[head].name, customer[head].time[0], customer[head].time[1]);
            double sum = 0;
            for(int j=head; j<tail-1; j++){
                if(customer[j].on_off == 0 && customer[j+1].on_off == 1){
                    double cost = cal_cost(customer[j].time, customer[j+1].time);
                    int time_min = cal_time(customer[j].time, customer[j+1].time);
                    printf("%s %s %d $%.2f\n", customer[j].time+3, customer[j+1].time+3, time_min, cost);
                    sum += cost;
                    j++;
                }
            }
            printf("Total amount: $%.2f\n", sum);
        }
        head = tail;
    }
    return 0;
}
