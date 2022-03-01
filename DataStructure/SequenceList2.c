#include <stdio.h>
#include <stdlib.h>
//2、动态分配
#define InitSize 10
struct SequenceList{
    int *data;
    int maxSize;
    int length;
};

//初始化
void InitList(struct SequenceList L){
    L.data = (int *)malloc(sizeof(int)*InitSize);
    L.length = 0;
    L.maxSize = InitSize;
}

//增加动态数组的长度
void IncreaseList(struct SequenceList L,int num){
    int *p = L.data;
    L.data = (int *)malloc(sizeof(int)*(InitSize+num));
    for(int i=0;i<L.length;i++){
        L.data[i]=p[i];
    }
    L.maxSize = num + InitSize;
    free(p);
}
int main(void){
    struct SequenceList sqlist;
    InitList(sqlist);

    IncreaseList(sqlist, 5);
    for(int i=0;i<sqlist.maxSize;i++){
        printf("%d, ",sqlist.data[i]);
    }
    return 0;
}