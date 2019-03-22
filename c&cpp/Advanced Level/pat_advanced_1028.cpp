#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
    char id[7];
    char name[9];
    int grade;
}stu[100000];

int sort_flag = 0; //1, 2, 3

bool cmp(node a, node b){
    switch(sort_flag){
    case 1:
        return strcmp(a.id, b.id) < 0;
    case 2:
        if(strcmp(a.name, b.name) != 0)
            return strcmp(a.name, b.name) < 0;
        else
            return strcmp(a.id, b.id) < 0;
    case 3:
        if(a.grade != b.grade)
            return a.grade < b.grade;
        else
            return strcmp(a.id, b.id) < 0;
    }
}

int main(){
    int N;
    scanf("%d %d", &N, &sort_flag);
    for(int i=0; i<N; i++){
        scanf("%s %s %d", stu[i].id, stu[i].name, &stu[i].grade);
    }
    sort(stu, stu+N, cmp);
    for(int i=0; i<N; i++){
        printf("%s %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }
}
