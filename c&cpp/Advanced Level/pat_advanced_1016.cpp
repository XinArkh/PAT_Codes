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
    int circle_flag = 0;
    char* head_name = customer[head].name;
    while(strcmp(customer[tail].name, head_name) = 0){
        if(customer[tail].on_off != customer[head].on_off){
            circle_flag = 1;
        }
        tail += 1;
    }

    return 0;
}
