#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

long long str2dec(string s, int radix){
    long long val = 0;
    int index = 0;
    for(string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); rit++){
        val += pow(radix, index++) * (isdigit(*rit)? *rit-'0': *rit-'a'+10);
    }
    return val;
}

long long query_radix(string s, long long val){
    char max_s = *max_element(s.begin(), s.end());
    long long low = (isdigit(max_s)? max_s-'0': max_s-'a'+10) + 1;
    long long high = max(low, val) + 1;
    while(low<=high){
        long long mid = (low + high) / 2;
        long long res = str2dec(s, mid);
        if(res<0 || res>val) high = mid - 1;
        else if(res == val) return mid;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    long long ans = tag==1? query_radix(N2, str2dec(N1, radix)): query_radix(N1, str2dec(N2, radix));
    ans==-1? cout << "Impossible": cout << ans;
    return 0;
}
