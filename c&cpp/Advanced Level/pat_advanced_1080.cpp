#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    int id;
    int GE, GI;
    int total;
    vector<int> choice;
};

bool cmp_grade(node a, node b){
    if(a.total != b.total) return a.total > b.total;
    else return a.GE > b.GE;
}

bool cmp_id(node a, node b){
    return a.id < b.id;
}

int main(){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    vector<node> app(N), sch[M];
    int quota[M];
    int acc_num[M]={0};
    for(int i=0; i<M; i++){
        scanf("%d", quota+i);
    }
    for(int i=0; i<N; i++){
        app[i].id = i;
        scanf("%d %d", &app[i].GE, &app[i].GI);
        app[i].total = app[i].GE + app[i].GI;
        app[i].choice.resize(K);
        for(int j=0; j<K; j++)
            scanf("%d", &app[i].choice[j]);
    }
    sort(app.begin(), app.end(), cmp_grade);
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            int school = app[i].choice[j];
            if(quota[school]>0){
                sch[school].push_back(app[i]);
                quota[school]--;
                acc_num[school]++;
                break;
            }
            else{
                int last_index = acc_num[school] - 1;
                node last_app = sch[school][last_index];
                if(app[i].total==last_app.total && app[i].GE==last_app.GE){
                    sch[school].push_back(app[i]);
                    acc_num[school]++;
                    break;
                }
            }
        }
    }
    for(int i=0; i<M; i++){
        sort(sch[i].begin(), sch[i].end(), cmp_id);
        for(int j=0; j<acc_num[i]; j++){
            if(j!=0) printf(" ");
            printf("%d", sch[i][j].id);
        }
        printf("\n");
    }
    return 0;
}
