#include<cstdio>
#include<map>
using namespace std;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    map<int, int> mp;
    for(int i=0; i<N; i++){
        int tmp;
        scanf("%d", &tmp);
        mp[tmp]++;
    }
    int V1=-1, V2, v1, v2;
    for(map<int, int>::iterator it = mp.begin(); it!=mp.end(); it ++){
        v1 = it->first;
        v2 = M - v1;
        if((v1!=v2 && mp[v1]>0 && mp[v2]>0) || (mp[v2]>=2)){
            V1 = v1;
            V2 = v2;
            break;
        }
    }
    if(V1==-1){
        printf("No Solution");
    }
    else{
        printf("%d %d", V1, V2);
    }
    return 0;
}
