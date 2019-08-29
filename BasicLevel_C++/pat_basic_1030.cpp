#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, p;
    scanf("%d %d", &N, &p);
    vector<long long> a(N);
    for(int i=0; i<N; i++){
        scanf("%lld", &a[i]);
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for(int i=0; i<N; i++){
        int j = upper_bound(a.begin()+i+1, a.end(), (long long)a[i]*p) - a.begin();
        ans = max(ans, j-i);
    }
    printf("%d", ans);
    return 0;
}
