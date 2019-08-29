#include <cstdio>
#include <cstdlib>

int main()
{
    int n, schID, score;
    scanf("%d", &n);

    /*int school[n] = {0};  //创建数组，这里devcpp和code blocks不报错，但实际上是错的
    Reference：https://bbs.csdn.net/topics/391898322
    “C自C99开始，在特定条件下允许使用变量作为数组长度定义数组，C++ 至今不允许这种用法”
    */
    //使用动态数组：https://www.cnblogs.com/biantiao/p/3866645.html
    int* school = (int *)malloc(n*sizeof(int));  // 请求分配
    // 验证是否分配成功
    if(school == NULL){
        printf("分配内存空间失败，程序退出！");
        return 1;
    }
    // 初始化分配到的内存
    for(int i = 0; i < n; i++){
        school[i] = 0;
    }

    for(int i = 0; i < n; i++){
        scanf("%d%d", &schID, &score);
        school[schID-1] += score;
    }
    int maxID, maxS = -1;
    for(int i = 0; i < n; i++){
        if(school[i] > maxS){
            maxID = i + 1;
            maxS = school[i];
        }
    }
    printf("%d %d\n", maxID, maxS);

    free(school);  // 最后要释放分配到的内存
    return 0;
}
