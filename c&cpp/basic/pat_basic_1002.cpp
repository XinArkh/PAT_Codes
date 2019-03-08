#include <cstdio>

void pinyin(int n);

int main()
{
    char n[100];
    scanf("%s", n);
    int sum = 0;
    for(int i = 0; n[i] != '\0'; i++){
        sum += n[i] - '0';
    }
    int sum_inv[100];
    int len = 0;
    do{
        sum_inv[len++] = sum % 10;
        sum /= 10;
    } while(sum > 0);
    for(int i = len - 1; i >= 0; i--){
        pinyin(sum_inv[i]);
        if(i != 0) printf(" ");
    }

    return 0;
}

inline void pinyin(int n)
{
    switch(n){
    case 0:
        printf("ling");
        break;
    case 1:
        printf("yi");
        break;
    case 2:
        printf("er");
        break;
    case 3:
        printf("san");
        break;
    case 4:
        printf("si");
        break;
    case 5:
        printf("wu");
        break;
    case 6:
        printf("liu");
        break;
    case 7:
        printf("qi");
        break;
    case 8:
        printf("ba");
        break;
    case 9:
        printf("jiu");
        break;
    }
}
