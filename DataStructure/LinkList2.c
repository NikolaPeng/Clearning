#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
单链表的插入
-------------
按位序插入，带头节点:
头节点可视为第0个节点；
在第i-1个节点后插入第i个节点；
-------------
按位序插入，不带头节点：
不存在第0个节点，因此i=1时需要特殊处理；
*/
struct LNode{
    int data;
    struct LNode *next;
};
typedef struct LNode LNode, *LinkList;

//在第i个节点位置插入元素e（带头节点）
bool LinkListInsert1(LinkList L,int i,int e){
    if(i<1)
        return false;
    LNode *p;   //指针p指向当前扫描到的节点；
    int j=0;    //当前p指向第几个节点；
    p = L;      //p指向L的头节点
    while(p!=NULL&&j<i-1){  //循环，找到L的第i-1个节点；
        p=p->next;
        j++;
    }
    if(p==NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//在第i个节点位置插入元素e（不带头节点）
bool LinkListInsert2(LinkList L,int i,int e){
    if(i<1){
        return false;
    }
    //如果插入的是第一个节点，要特殊处理；
    if(i==1){
        LNode *s=(LNode *)malloc(sizeof(LNode *));
        s->data = e;
        s->next = L;
        L= s;
    }
    LNode *p;
    int j=1;
    p = L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; 
    return true;
}

//指定节点的后插操作
bool InsertNextNode(LNode *p,int e){
    //在p节点之后插入数据e
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode *));
    if(s==NULL){    //内存分配失败
        return false;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//指定节点的前插操作
bool InsertPeriorNode(LNode *p,int e){
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL){
        return false;
    }
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

//按位序删除（带头节点）
//删除表中第i个元素：找到第i-1个节点，将其指向第i+1个节点；
bool DeleteNode(LinkList L,int i,int e){
    if(i<1){
        return false;
    }
    LNode *p;
    int j=0;
    p = L;
    while(p!=NULL&&j<i-1){  //循环找到第i-1个节点
        p=p->next;
        j++;
    }
    if(p==NULL||p->next==NULL){
        return false;
    }
    LNode *q;
    q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

//指定节点的删除
//删除指定节点p
bool DeleteNode2(LNode *p){
    if(p==NULL)
        return false;
    LNode *q = p->next; //q指向p的后继节点
    p->data = p->next->data;    //将p后继节点的数据赋给p
    p->next=q->next;    //将p指向q的后面节点
    free(q);    //释放q
    return true;
}