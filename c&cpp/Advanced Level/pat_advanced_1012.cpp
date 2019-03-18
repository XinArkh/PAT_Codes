#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct Student{
    int id, best;
    int grade[4], stu_rank[4];  //ordering: A C M E
}stu[2000];

char class_name[5] = {'A', 'C', 'M', 'E'};
int loc[1000000] = {-1}, grade_flag = -1;

bool cmp(Student a, Student b){
    return a.grade[grade_flag] > b.grade[grade_flag];
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round((stu[i].C + stu[i].M + stu[i].E) / 3.0);
    }
    for(grade_flag=0; grade_flag<=3; grade_flag++){
        sort(stu, stu+N, cmp);
        int local_rank = 1;
        for(int j=0; j<N; j++){
            if(j>0 && stu[j].grade[grade_flag != stu[j-1].grade[grade_flag]) local_rank = j + 1;
            stu[j].stu_rank[grade_flag] = local_rank;
        }
    }
    for(int i=0; i<N; i++){
        loc[stu[i].id] = i;
        int tmp_best = stu[i].stu_rank[0];
        stu[i].best = 0;
        for(int j=1; j<4; j++){
            if(stu[i].stu_rank[j] < tmp_best){
                tmp_best = stu[i].stu_rank[j];
                stu[i].best = j;
            }
        }
    }
    int query;
    for(int i=0; i<M; i++){
        scanf("%s", &query);

    }
}
