#include<cstdio>
#include<map>
using namespace std;

int main(){
    int N, K, tmp;
    scanf("%d", &N);
    map<int, int> score_num;
    for(int i=0; i<N; i++){
        scanf("%d", &tmp);
        score_num[tmp]++;
    }
    scanf("%d", &K);
    for(int i=0; i<K; i++){
        scanf("%d", &tmp);
        if(i != 0) printf(" ");
        printf("%d", score_num[tmp]);
    }
    return 0;
}
