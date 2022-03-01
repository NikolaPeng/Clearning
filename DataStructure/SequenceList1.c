#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*  顺序表：用顺序存储方式实现线性表
    1、实现方式：分为静态分配和动态分配、以及初始化
    2、顺序表的插入与删除
    3、顺序表的查找
        分为按值查找和按位查找
*/

//1、静态分配
#define MaxSize 10
struct SequenceList{
     int data[MaxSize];
     int length;
};
//初始化该顺序表
void InitList(struct SequenceList L){
    for(int i=0;i<MaxSize;i++){
        L.data[i]=0;
    }
    L.length=0;
}

//插入与删除
bool ListInsert(struct SequenceList L,int i,int num){
    if(i<0||i>L.length+1){
        return false;
    }if(i>MaxSize){
        return false;
    }
    for(int j=L.length-1;j>=i;j--){
        L.data[j] = L.data[j-1];
    }
    L.data[i-1]=num;
    L.length++;
    return true;
}

bool ListDelete(struct SequenceList L,int i,int num){
    if(i<0||i>L.length){
        return false;
    }
    num = L.data[i-1];
    for(int j=i-1;j<L.length-1;j++){
        L.data[j]=L.data[j+1];
    }
    L.length--;
    return true;
}

int main(void){
    struct SequenceList sqlist;
    InitList(sqlist);
    ListInsert(sqlist,5,1);
    ListDelete(sqlist,2,0);
    return 0;
}