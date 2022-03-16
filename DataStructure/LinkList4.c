#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
单链表的建立
分为尾插法和头插法
只研究有头节点的情况
*/
struct LNode{
    int data;
    struct LNode *next;
};
typedef struct LNode LNode, *LinkList;

//1、尾插法建立单链表

//初始化一个单链表
bool InitLink(LinkList L){
    L = (LNode *)malloc(sizeof(struct LNode));
    if(L == NULL){
        return false;
    }
    L->next =NULL;
    return true;
}

//在第i个元素的位置插入e
bool LinkInsert(LinkList L,int i, int e){
    if(i<0){
        return false;
    }
    LNode *p;
    int j=0;
    p = L;
    while(p!=NULL&&j<i-1){
        p = p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//尾插法
LinkList List_TailInsert(LinkList L){
    int x;
    LNode *p = (LNode *)malloc(sizeof(LNode));  //建立头节点
    LNode *s,*r=L;
    scanf("%d",&x);
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;    //在r节点之后插入x
        r = s;  //r指向新的表尾节点
        scanf("%d",&x);
    }
    r->next = NULL; //尾节点设置为空
    return L;
}


//头插法

LinkList List_HeadInsert(LinkList L){
    int x;
    LNode *s;
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d",&x);
    while(x!=9999){
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);
    }
    return L;
}