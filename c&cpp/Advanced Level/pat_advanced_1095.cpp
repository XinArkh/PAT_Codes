#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct node{
    char id[8];
    int time;
    int status;
};

bool cmp_id_time(node a, node b){
    if(strcmp(a.id, b.id)!=0) return strcmp(a.id, b.id) < 0;
    else return a.time < b.time;
}

bool cmp_time(node a, node b){
    return a.time < b.time;
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    vector<node> rec(N), car;
    map<string, int> park_time;
    for(int i=0; i<N; i++){
        int hh, mm, ss;
        char status[4];
        scanf("%s %d:%d:%d %s", rec[i].id, &hh, &mm, &ss, status);
        rec[i].time = hh*60*60 + mm*60 + ss;
        rec[i].status = strcmp(status, "in")==0?1:-1;
    }
    sort(rec.begin(), rec.end(), cmp_id_time);
    int max_time = -1;
    for(int i=0; i<N-1; i++){
        if(strcmp(rec[i].id, rec[i+1].id)==0 && rec[i].status==1 && rec[i+1].status==-1){
            car.push_back(rec[i]);
            car.push_back(rec[i+1]);
            park_time[rec[i].id] += rec[i+1].time - rec[i].time;
            if(max_time < park_time[rec[i].id])
                max_time = park_time[rec[i].id];
        }
    }
    sort(car.begin(), car.end(), cmp_time);
    vector<int> cnt(car.size());
    for(int i=0; i<car.size(); i++){
        if(i==0) cnt[i] = car[i].status;
        else cnt[i] = cnt[i-1] + car[i].status;
    }
    for(int i=0; i<K; i++){
        int hh, mm, ss;
        int curr_time;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        curr_time = hh*60*60 + mm*60 + ss;
        for(int j=0; j<car.size(); j++){
            if(curr_time < car[j].time){
                printf("%d\n", cnt[j-1]);
                break;
            }
            else if(j == car.size()-1)
                printf("%d\n", cnt[j]);
        }
    }
    for(map<string, int>::iterator it = park_time.begin(); it != park_time.end(); it++){
        if(it->second == max_time)
            printf("%s ", it->first.c_str());
    }
    printf("%02d:%02d:%02d", max_time/(60*60), (max_time%(60*60))/60, max_time%60);
    return 0;
}
