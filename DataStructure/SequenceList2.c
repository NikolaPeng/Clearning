#include <stdio.h>
#include <stdlib.h>
//2、动态分配
#define InitSize 10
struct SequenceList{
    int *data;
    int maxSize;
    int length;
};

//初始化顺序表
void InitList(struct SequenceList L){
    L.data = (int *)malloc(sizeof(int)*InitSize);
    L.length = 0;
    L.maxSize = InitSize;
}

//增加动态数组的长度
void IncreaseList(struct SequenceList L,int len){
    int *p = L.data;
    L.data = (int *)malloc(sizeof(int)*(InitSize+len));
    for(int i=0;i<L.length;i++){
        L.data[i]=p[i];
    }
    L.maxSize = len + InitSize;
    free(p);
}
//顺序表的查找：1、按位查找；2、按值查找
int getElem(struct SequenceList L,int i){
    return L.data[i-1];
}
int locateElem(struct SequenceList L,int num){
    for(int j=0;j<L.length;j++){
        if(L.data[j]==num){
            return j+1;
        }
    }
    return 0;
}

int main(void){
    struct SequenceList sqlist;
    InitList(sqlist);
    IncreaseList(sqlist, 5);
    
    return 0;
}