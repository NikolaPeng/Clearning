//队列：只允许在一端插入、另一端删除的线性表。
//先进入队列的先出队
//队尾：允许插入的一端
//队头：允许删除的一端
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10
//队列的顺序实现
typedef struct{
    int data[MaxSize];
    int rear, front;    //队头指针、队尾指针
}SqQueue;

//初始化
bool InitQueue(SqQueue queue){
    //队头队尾指针均指向0
    queue.front = queue.rear = 0;
    return true;
}

//判断队列是否为空
bool EmptyQueue(SqQueue q){
    if(q.rear == q.front){
        return true;
    }else{
        return false;
    }
}
//队列在使用顺序结构时，会出现假溢出，被删除的空间永远也用不到。
//为了解决假溢出，可以使用循环队列

//入队
bool Enqueue(SqQueue q,int x){
    if((q.rear+1)%MaxSize == q.front)
        return false;
    q.data[q.rear] = x;
    q.rear = (q.rear+1)%MaxSize;
    return true;
}

//出队
bool Dequeue(SqQueue q,int x){
    if(q.front==q.rear)
        return false;
    x = q.data[q.front];
    q.front = (q.front+1)%MaxSize;
    return true;
}

//这里使用空闲单元法，即牺牲一个单元。
//判断队满
bool FullQueue(SqQueue q){
    if(q.front==(q.rear+1)%MaxSize)
        return false;
    else
        return true;
}

//如果不想牺牲这一个存储单元，可以在定义队列时加入一个变量tag=0
//当删除队列元素时，执行tag--；当加入元素时，执行tag++。

