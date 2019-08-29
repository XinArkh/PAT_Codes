#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> sum(N+1), ans_index;
    sum[0] = 0;
    for(int i=1; i<N+1; i++){
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    int near_M = sum[N];
    for(int i=1; i<N+1; i++){
        int j = lower_bound(sum.begin()+i, sum.end()-1, sum[i-1]+M) - sum.begin();
        int tmp_M = sum[j]-sum[i-1];
        if(tmp_M > near_M) continue;
        if(tmp_M >= M){
            if(tmp_M < near_M){
                near_M = tmp_M;
                ans_index.clear();
            }
            ans_index.push_back(i);
            ans_index.push_back(j);
            continue;
        }
    }
    for(int i=0; i<ans_index.size(); i+=2){
        printf("%d-%d\n", ans_index[i], ans_index[i+1]);
    }
}
