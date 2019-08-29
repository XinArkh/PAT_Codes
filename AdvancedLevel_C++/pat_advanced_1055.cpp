#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct node{
    char name[9];
    int age, worth;
}ps[100000];

bool cmp(node a, node b){
    if(a.worth != b.worth) return a.worth > b.worth;
    else if(a.age != b.age) return a.age < b.age;
    else return strcmp(a.name, b.name) < 0;
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%s %d %d", ps[i].name, &ps[i].age, &ps[i].worth);
    }
    sort(ps, ps+N, cmp);
    for(int i=0; i<K; i++){
        int M, Amin, Amax;
        scanf("%d %d %d", &M, &Amin, &Amax);
        printf("Case #%d:\n", i+1);
        int total_print = 0;
        for(int j=0; j<N && total_print<M; j++){
            if(ps[j].age>=Amin && ps[j].age<=Amax){
                printf("%s %d %d\n", ps[j].name, ps[j].age, ps[j].worth);
                total_print++;
            }
        }
        if(total_print == 0) printf("None\n");
    }
}
