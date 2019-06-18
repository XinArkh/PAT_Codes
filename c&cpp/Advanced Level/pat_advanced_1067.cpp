#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    int swapNum = 0, tmp;
    vector<int> pos(N);
    for(int i=0; i<N; i++){
        scanf("%d", &tmp);
        pos[tmp] = i;
    }
    for(int i=0; i<N; i++){
        if(pos[i] != i){
            while(pos[0] != 0){
                swap(pos[0], pos[pos[0]]);
                swapNum++;
            }
            if(pos[i] != i){
                swap(pos[0], pos[i]);
                swapNum++;
            }
        }
    }
    printf("%d", swapNum);
    return 0;
}
