#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmp(string a, string b){
    return a+b < b+a;
}

int main(){
    int N;
    cin>>N;
    string num[N];
    for(int i=0; i<N; i++){
        cin>>num[i];
    }
    sort(num, num+N, cmp);
    string ans;
    for(int i=0; i<N; i++){
        ans += num[i];
    }
    while(ans[0]=='0' && ans.length() > 1){
        ans.erase(ans.begin());
    }
    cout<<ans;
    return 0;
}
