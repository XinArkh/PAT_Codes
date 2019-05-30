#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){return a > b;}

int main(){
    int K;
    scanf("%d", &K);
    vector<int> vec(K);
    map<int, bool> m;
    for(int i=0; i<K; i++){
        int n;
        scanf("%d", &n);
        vec[i] = n;
        while(n!=1){
            if(n%2!=0) n = 3*n+1;
            n /= 2;
            if(m[n]==true) break;
            m[n] = true;
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    bool space = false;
    for(int i=0; i<K; i++){
        if(m[vec[i]]==false){
            if(!space) space = true;
            else printf(" ");
            printf("%d", vec[i]);
        }
    }
    return 0;
}
