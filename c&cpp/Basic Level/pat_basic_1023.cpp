#include<cstdio>

int main(){
    int num[10] = {0}, head=0;
    for(int i=0; i<10; i++){
        scanf("%d", num+i);
        if(head==0 && num[i]>0) head = i;
    }
    printf("%d", head);
    num[head]--;
    for(int i=0; i<10; i++){
        while(num[i]--) printf("%d", i);
    }
    return 0;
}
