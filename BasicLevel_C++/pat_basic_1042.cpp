#include<cstdio>
#include<cctype>
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    map<char, int> num;
    for(string::iterator it=str.begin();it!=str.end();it++)
        if(isalpha(*it)) num[tolower(*it)]++;
    char max_char = 0;
    int max_num = 0;
    for(map<char, int>::iterator it=num.begin();it!=num.end();it++)
        if(it->second>max_num){
            max_char = it->first;
            max_num = it->second;
        }
    printf("%c %d", tolower(max_char), max_num);
    return 0;
}
