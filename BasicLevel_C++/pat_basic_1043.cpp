#include<cstdio>
#include<cstring>

int main(){
    int char_map[128] = {0};
    char str[10001];
    scanf("%s", str);
    for(int i=0; i<strlen(str); i++)
        char_map[str[i]]++;
    while(char_map['P']>0 || char_map['A']>0 || char_map['T']>0
          || char_map['e']>0 || char_map['s']>0 || char_map['t']>0){
        if(char_map['P']-- >0) printf("%c", 'P');
        if(char_map['A']-- >0) printf("%c", 'A');
        if(char_map['T']-- >0) printf("%c", 'T');
        if(char_map['e']-- >0) printf("%c", 'e');
        if(char_map['s']-- >0) printf("%c", 's');
        if(char_map['t']-- >0) printf("%c", 't');
    }
    return 0;
}
