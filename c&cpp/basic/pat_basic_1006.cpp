#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void Bai(char c);
void Shi(char c);
void Ge(char c);

int main()
{
    string in_num;
    cin>>in_num;
    switch(in_num.length()){
        case 3:
            Bai(in_num[0]);
            Shi(in_num[1]);
            Ge(in_num[2]);
            break;
        case 2:
            Shi(in_num[0]);
            Ge(in_num[1]);
            break;
        case 1:
            Ge(in_num[0]);
            break;
    }

    return 0;
}

inline void Bai(char c)
{
    for(int i = 0; i < c - '0'; i++){
        printf("B");
    }
}

inline void Shi(char c)
{
    for(int i = 0; i < c - '0'; i++){
        printf("S");
    }
}

inline void Ge(char c)
{
    for(int i = 0; i < c - '0'; i++){
        printf("%d", i+1);
    }
}
