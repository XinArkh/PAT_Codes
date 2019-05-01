#include<cstdio>
#include<map>
using namespace std;

int main(){
    int N, tmp, num = -1;
    scanf("%d", &N);
    map<int, int> mp1;
    map<int, int> mp2;
    for(int i=0; i<N; i++){
        scanf("%d", &tmp);
        mp1[i] = tmp;
        mp2[tmp]++;
    }
    for(map<int, int>::iterator it=mp1.begin(); it!=mp1.end(); it++)
        if(mp2[it->second]==1){
            num = it->second;
            break;
        }
    if(num==-1) printf("None");
    else printf("%d", num);
    return 0;
}
