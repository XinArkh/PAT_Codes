#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    string a, b;
    cin>>a>>b;
    map<char, int> color;
    int miss = 0;
    for(string::iterator it=a.begin(); it!=a.end(); it++)
        color[*it]++;
    for(string::iterator it=b.begin(); it!=b.end(); it++){
        color[*it]--;
        if(color[*it]<0) miss++;
    }
    if(miss>0) printf("No %d", miss);
    else printf("Yes %d", a.length()-b.length());
    return 0;
}
