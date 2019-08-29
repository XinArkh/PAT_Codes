#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
    char name[11];
    char id[11];
    int grade;
};

bool cmp(node a, node b){
    return a.grade >= b.grade;
}

int main(){
    int N;
    scanf("%d", &N);
    vector<node> stu(N+1);
    for(int i=0; i<N; i++){
        scanf("%s %s %d", stu[i].name, stu[i].id, &stu[i].grade);
    }
    sort(stu.begin(), stu.end(), cmp);
    int grade1, grade2;
    scanf("%d %d", &grade1, &grade2);
    if(stu[0].grade<grade1 || stu[N-1].grade>grade2){
        printf("NONE\n");
    }
    else{
        for(int i=0; i<N; i++){
            if(stu[i].grade>=grade1 && stu[i].grade<=grade2)
                printf("%s %s\n", stu[i].name, stu[i].id);
            else if(stu[i].grade<grade1)
                break;
        }
    }
    return 0;
}
