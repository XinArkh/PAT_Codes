#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int id;
    int score[6] = {-1, -1, -1, -1, -1, -1};
    bool pass_flag = false;
    int total = 0;
    int perfect = 0;
};

bool cmp(node a, node b){
    if(a.total != b.total) return a.total > b.total;
    else if(a.perfect != b.perfect) return a.perfect > b.perfect;
    else return a.id < b.id;
}

int main(){
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    vector<node> usr(N+1);
    int p[6];
    for(int i=1; i<=K; i++) scanf("%d", p+i);
    for(int i=0; i<M; i++){
        int u_id, p_id, score;
        scanf("%d %d %d", &u_id, &p_id, &score);
        if(score != -1) usr[u_id].pass_flag = true;
        if(score == -1 && usr[u_id].score[p_id] == -1)
            usr[u_id].score[p_id] = 0;
        if(score == p[p_id] && usr[u_id].score[p_id] < p[p_id])
            usr[u_id].perfect++;
        if(score > usr[u_id].score[p_id])
            usr[u_id].score[p_id] = score;
    }
    for(int i=1; i<=N; i++){
        usr[i].id = i;
        for(int j=1; j<=K; j++){
            if(usr[i].score[j] > -1)
                usr[i].total += usr[i].score[j];
        }
    }
    sort(usr.begin()+1, usr.end(), cmp);
    int r = 1;
    for(int i=1; i<=N && usr[i].pass_flag; i++){
        if(i>1 && usr[i].total != usr[i-1].total) r = i;
        printf("%d %05d %d", r, usr[i].id, usr[i].total);
        for(int j=1; j<=K; j++){
            if(usr[i].score[j] > -1) printf(" %d", usr[i].score[j]);
            else printf(" -");
        }
        printf("\n");
    }
    return 0;
}
