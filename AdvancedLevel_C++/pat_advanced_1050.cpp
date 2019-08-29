#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int len1 = str1.size();
    for(int i=0; i<len1; i++)
        if(str2.find(str1[i])==string::npos)
            printf("%c", str1[i]);
    return 0;
}
