#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct goods{
    double ku;
    double zong;
    double dan;
};

bool cmp(goods a, goods b){return a.dan >= b.dan;}

int main(){
    int N, D;
    scanf("%d %d", &N, &D);
    vector<goods> g(N);
    for(int i=0; i<N; i++) scanf("%lf", &g[i].ku);
    for(int i=0; i<N; i++){
        scanf("%lf", &g[i].zong);
        g[i].dan = (double) g[i].zong / g[i].ku;
    }
    sort(g.begin(), g.end(), cmp);
    double sum = 0.0;
    for(int i=0; i<N; i++){
        if(D >= g[i].ku){
            D -= g[i].ku;
            sum += g[i].zong;
        }
        else{
            sum += g[i].dan * D;
            break;
        }
    }
    printf("%.2f", sum);
    return 0;
}
