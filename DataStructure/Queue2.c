//队列的链式实现
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10

//队列的链式实现
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

//初始化队列（带头节点）
bool InitLinkQueue1(LinkQueue q){
    q.front = q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    q.front->next = NULL;
    return true;
}

//初始化队列（不带头节点）
bool InitLinkQueue2(LinkQueue q){
    q.front = NULL;
    q.rear = NULL;
    return true;
}

//判断队列是否为空：头节点和尾节点是否指向同一个位置
bool LQueueIsEmpty(LinkQueue q){
    if(q.front == q.rear)
        return true;
    else
        return false;
}
//入队（带头节点）
bool EnLinkQueue1(LinkQueue q,int x){
    LinkNode *s;
    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    q.rear->next = s;
    q.rear = s;
    return true;
}

//入队（不带头节点）
bool EnLinkQueue2(LinkQueue q,int x){
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if(q.front == NULL){ //队列是否为空
        q.front = s;
        q.rear = s;
    }else{
        q.rear->next = s;
        q.rear = s;
    }
    return true;
}

//出队（带头节点）
bool DeLinkQueue1(LinkQueue q,int x){
    if(q.front == q.rear)
        return false;
    LinkNode *p = q.front->next;
    x = p->data;
    q.front->next = p->next;
    if(p == q.rear)
        q.rear = q.front;
    free(p);
    return true;
}

//出队（不带头节点）
bool DeLinkQueue2(LinkQueue q){
    int x;
    if(q.front == q.rear){
        return false;
    }
    LinkNode *p = q.front->next;
    x = p->data;
    q.front = p->next;
    if(q.rear == p){
        q.rear = NULL;
        q.front = NULL;
    }
    free(p);
    return true;
}