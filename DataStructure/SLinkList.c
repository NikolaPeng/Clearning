//静态链表：分配一整片的连续存储空间，各个结点集中安置；
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10

struct Node{
    int data;
    int next;
};

typedef struct Node SLinkList[MaxSize];
//SLinkList是一个静态链表、Node型数组
