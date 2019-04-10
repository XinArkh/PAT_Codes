#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i=0; i<s2.length(); i++){
        if(s1.find('+') != string::npos && isupper(s2[i])) continue;
        if(s1.find(toupper(s2[i])) != string::npos) continue;
        cout<<s2[i];
    }
    return 0;
}
