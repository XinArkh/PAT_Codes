#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student
{
    char id[14];
    int score;
    int location_number;
    int location_rank;
} stu[30000];

bool cmp(Student a, Student b)
{
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}

int main()
{
    int N, K, total_number = 0;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &K);
        for(int j=0; j<K; j++){
            scanf("%s %d", stu[total_number].id, &stu[total_number].score);
            stu[total_number].location_number = i+1;
            total_number++;
        }
        sort(stu+total_number-K, stu+total_number, cmp);
        stu[total_number-K].location_rank = 1;
        for(int j=1; j<K; j++){
            if(stu[total_number-K+j].score == stu[total_number-K+j-1].score)
                stu[total_number-K+j].location_rank = stu[total_number-K+j-1].location_rank;
            else
                stu[total_number-K+j].location_rank = j + 1;
        }
    }
    sort(stu, stu+total_number, cmp);
    printf("%d\n", total_number);
    int final_rank = 1;
    for(int i=0; i<total_number; i++){
        if(i>0 && stu[i].score != stu[i-1].score) final_rank = i + 1;
        printf("%s %d %d %d\n", stu[i].id, final_rank, stu[i].location_number, stu[i].location_rank);
    }
    return 0;
}
