#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//双链表
//定义一个双链表
struct DNode{
    int data;
    struct DNode *next,*prior;
};
typedef struct DNode DNode, *DLinkList;

//双链表的初始化（带头节点）
bool InitDNode(DLinkList L){
    L = (DLinkList)malloc(sizeof(DNode));
    if(L == NULL)
        return false;
    L->next = NULL;
    L->prior = NULL;
    return true;
}
//判断双链表是否为空
bool EmptyDNode(DLinkList L){
    if(L->next == NULL)
        return true;
    else 
        return false;
}

//双链表的插入
//在p节点后面插入q节点。（要注意的特殊情况是：如果p是最后一个节点）
bool InsertNextDNode(DNode *p,DNode *q){
    if(p==NULL || q==NULL){ //非法参数
        return false;
    }
    q->next = p->next;
    if(p->next != NULL)
        p->next->prior = q;
    q->prior = p;
    p->next =q;
    return true;
}

//删除p节点的后继节点
bool DeleteNextDNode(DNode *p){
    if(p==NULL)
        return false;
    DNode *q = p->next;
    if(q==NULL)
        return false;
    p->next =q->next;
    if(p->next!=NULL){
        q->next->prior = p;
    }
    free(q);
    return true;
}

//删除双链表
bool DeleteDLinkList(DLinkList L){
    while(L->next != NULL){
        DeleteNextDNode(L);
    }
    free(L);
    return true;
}