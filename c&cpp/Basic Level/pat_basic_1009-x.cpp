/*ע�⣺PAT��c++����������֧��gets()����������c������cin.getline()*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str[80];
    gets(str);
    int len = strlen(str);
    int i = len - 1, j = len - 1;
    while(j >= 0){
        while(i >= 0 && str[i] != ' '){
            i--;
        }
        for(int k = i + 1; k <= j; k++){
            printf("%c", str[k]);
        }
        if(str[i] == ' ') printf(" ");
        j = --i;
    }

    return 0;
}
