#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
单链表的查找：分为按位查找、按值查找
这里只讨论有头节点的情况下
*/
struct LNode{
    int data;
    struct LNode *next;
};
typedef struct LNode LNode, *LinkList;

//1、按位查找，返回第i个元素：
LNode *GetNode(LinkList L,int i){
    if(i<0){
        return NULL;
    }
    LNode *p;
    int j=0;
    p= L;
    if(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    return p;
}

//2、按值查找，找到数据==e的节点
LNode* LocateNode(LinkList L,int e){
    LNode *p = L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}