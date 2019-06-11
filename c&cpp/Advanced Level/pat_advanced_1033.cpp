#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int inf = 999999999;

struct station{
    double p;
    double d;
};

bool cmp(station a, station b){return a.d <= b.d;}

int main(){
    double c_max, d, d_avg;
    int n;
    scanf("%lf %lf %lf %d", &c_max, &d, &d_avg, &n);
    vector<station> sta(n+1);
    for(int i=0; i<n; i++){
        scanf("%lf %lf", &sta[i].p, &sta[i].d);
    }
    sta[n].p = 0; sta[n].d = d;
    sort(sta.begin(), sta.end(), cmp);
    if(sta[0].d != 0) printf("The maximum travel distance = 0.00");
    else{
        int now_sta = 0;
        double max_delta_dis = c_max * d_avg, tot_pri = 0.0, now_tank = 0.0;
        while(now_sta < n){
            double min_price = inf;
            int goal_sta = -1;
            for(int i = now_sta+1; i <= n && sta[i].d - sta[now_sta].d <= max_delta_dis; i++){
                if(sta[i].p < min_price){
                    min_price = sta[i].p;
                    goal_sta = i;
                    if(min_price < sta[now_sta].p) break;
                }
            }
            if(goal_sta == -1) break;
            double required = (sta[goal_sta].d - sta[now_sta].d) / d_avg;
            if(sta[goal_sta].p < sta[now_sta].p){
                tot_pri += (required - now_tank) * sta[now_sta].p;
                now_tank = 0;
            }
            else{
                tot_pri += (c_max - now_tank) * sta[now_sta].p;
                now_tank = c_max - required;
            }
            now_sta = goal_sta;
        }
        if(now_sta != n) printf("The maximum travel distance = %.2f", sta[now_sta].d + max_delta_dis);
        else printf("%.2f", tot_pri);
    }
    return 0;
}
