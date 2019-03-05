#include <cstdio>
#include <cmath>

void Line1(int n, char c);
void Line2(int n, char c);

int main()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    Line1(n, c);printf("\n");
    int mid = int(round(n/2.0)) - 2;
    for(int i = 0; i < mid; i++){
        Line2(n, c);printf("\n");
    }
    Line1(n, c);printf("\n");

    return 0;
}

void Line1(int n, char c)
{
    for(int i = 0; i < n; i++){
        printf("%c", c);
    }
}

void Line2(int n, char c)
{
    for(int i = 0; i < n; i++){
        if(i == 0 || i == n-1) printf("%c", c);
        else printf(" ");
    }
}
