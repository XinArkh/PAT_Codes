#include <cstdio>
#include <cstdlib>

int main()
{
    int n, schID, score;
    scanf("%d", &n);

    /*int school[n] = {0};  //�������飬����devcpp��code blocks��������ʵ�����Ǵ��
    Reference��https://bbs.csdn.net/topics/391898322
    ��C��C99��ʼ�����ض�����������ʹ�ñ�����Ϊ���鳤�ȶ������飬C++ �������������÷���
    */
    //ʹ�ö�̬���飺https://www.cnblogs.com/biantiao/p/3866645.html
    int* school = (int *)malloc(n*sizeof(int));  // �������
    // ��֤�Ƿ����ɹ�
    if(school == NULL){
        printf("�����ڴ�ռ�ʧ�ܣ������˳���");
        return 1;
    }
    // ��ʼ�����䵽���ڴ�
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

    free(school);  // ���Ҫ�ͷŷ��䵽���ڴ�
    return 0;
}
