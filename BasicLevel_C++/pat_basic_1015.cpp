#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
    char id[9];
    int de, cai, sum;
    int level;
}stu[100000];

bool cmp(Student a, Student b){
    if(a.level != b.level) return a.level < b.level;
    else if(a.sum != b.sum) return a.sum > b.sum;
    else if(a.de != b.de) return a.de > b.de;
    else return strcmp(a.id, b.id) < 0;
}

int main(){
    int N, L, H;
    scanf("%d%d%d", &N, &L, &H);
    int M = N;
    for(int i=0; i<N; i++){
        scanf("%s %d %d", stu[i].id, &stu[i].de, &stu[i].cai);
        stu[i].sum = stu[i].de + stu[i].cai;
        if(stu[i].de>=H && stu[i].cai>=H) stu[i].level = 1;
        else if(stu[i].de>=H && stu[i].cai>=L) stu[i].level = 2;
        else if(stu[i].de>=stu[i].cai && stu[i].cai>=L) stu[i].level = 3;
        else if(stu[i].de>=L && stu[i].cai>=L) stu[i].level = 4;
        else{
            stu[i].level = 5;
            M--;
        }
    }
    sort(stu, stu+N, cmp);
    printf("%d\n", M);
    for(int i=0; i<M; i++){
        printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
    }

    return 0;
}
