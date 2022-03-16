//循环链表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//循环单链表表尾的next指针指向头节点
struct LNode{
    int data;
    struct LNode *next;
};
typedef struct LNode  LNode, *LinkList;
//初始化
bool InitLinkList(LinkList L){
    L = (LinkList)malloc(sizeof(LNode));
    if(L == NULL)
        return false;
    L->next =L;
    return true;
}

//循环双链表表尾指针next指向头节点，表头指针prior指向尾节点；
typedef struct DLNode{
    int data;
    struct DLNode *next;
    struct DLNode *prior;
}DLNode, *DLinkList;
//初始化
bool InitDLinkList(DLinkList L){
    L = (DLinkList)malloc(sizeof(DLNode));
    if(L == NULL)
        return false;
    L->next =L;
    L->prior =L;
    return true;
}