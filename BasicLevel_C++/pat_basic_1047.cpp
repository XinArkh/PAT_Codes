#include<cstdio>
#include<map>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    map<int, int> score;
    int team, member, s;
    for(int i=0; i<N; i++){
        scanf("%d-%d %d", &team, &member, &s);
        score[team] += s;
    }
    int max_team, max_score = -1;
    for(map<int, int>::iterator it=score.begin(); it!=score.end(); it++){
        if(it->second > max_score){
            max_team = it->first;
            max_score = it->second;
        }
    }
    printf("%d %d", max_team, max_score);
    return 0;
}
