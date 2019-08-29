#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int Nc, Np;
    scanf("%d", &Nc);
    vector<int> coupon(Nc);
    for(int i=0; i<Nc; i++){
        scanf("%d", &coupon[i]);
    }
    sort(coupon.begin(), coupon.end());
    scanf("%d", &Np);
    vector<int> product(Np);
    for(int i=0; i<Np; i++){
        scanf("%d", &product[i]);
    }
    sort(product.begin(), product.end());
    int sum = 0;
    int ip = 0;
    for(int ic=0; ic<Nc && coupon[ic]<0; ic++){
        if(ip<Np && product[ip]<0){
            sum += coupon[ic] * product[ip++];
        }
        else break;
    }
    ip = Np-1;
    for(int ic=Nc-1; ic>=0 && coupon[ic]>0; ic--){
        if(ip>=0 && product[ip]>0){
            sum += coupon[ic] * product[ip--];
        }
        else break;
    }
    printf("%d", sum);
    return 0;
}
