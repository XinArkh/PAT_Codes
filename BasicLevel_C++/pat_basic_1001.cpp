#include <cstdio>

int main()
{
    int step = 0;
    int callatz;
    scanf("%d", &callatz);
    while(callatz != 1){
        if(callatz % 2 ==0) callatz /= 2;
        else callatz = (3*callatz+1) / 2;
        step++;
    }
    printf("%d\n", step);
    return 0;
}
