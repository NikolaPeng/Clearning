#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
用代码定义单链表
*/
 struct LNode     //定义单链表的节点类型；
{
    int data;    //每个节点存放的数据；
    struct LNode *next;     //指针指向下一个节点；
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;
//要表示一个单链表时，只需要声明一个头指针L，指向单链表的第一个节点。
LNode *L;   //强调这是一个节点；
LinkList L; //强调这是一个单链表；

//不带头节点的单链表：
//初始化：
bool InitList1(LinkList L){
    L =NULL; //空表，暂时没有数据;
    return true;
}

void test1(){
    LinkList L;  //声明一个指向单链表的指针；
    InitList1(L);    //初始化L
}

//带头节点的单链表：
//初始化：
bool InitList2(LinkList L){
    L=(LNode *)malloc(sizeof(LNode)); //分配一个头节点
    if(L==NULL){
        return false;   //内存不足，分配失败
    }
    L->next = NULL;
    return true;
}

void test2(){
    LinkList L;
    InitList2(L);
}

//**头插法建立单链表的代码如下：
LinkList Head_InsertList(LinkList L){
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL; //创建空表
    int x;
    LNode *s;
    scanf ("%d",&x);
    while(x!=9999){     //创建新节点
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d",&x);

    }
    return L;
}