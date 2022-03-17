//栈（stack）：是只允许在一端进行插入和删除操作的线性表
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 10
//顺序栈的实现
//基本操作；初始化、出栈、进栈、获取栈顶元素、判断栈空、满
struct stack{
    int data[MaxSize];
    int top;
};
typedef struct stack sqstack;
//初始化
void InitStack(sqstack s){
    s.top = -1; //  初始化栈顶指针
}

void testStack(){
    sqstack s;
    InitStack(s);
    //后续的操作：增删改查等
}

//判断栈空
bool EmptyStack(sqstack s){
    if(s.top == -1)
        return true;
    else
        return false;
}

//进栈操作
bool push(sqstack s,int x){
    if(s.top == MaxSize-1)
        return false;
    s.top = s.top + 1;
    s.data[s.top] = x;
    return true;
}

//出栈操作
int pop(sqstack s){
    if(s.top == -1)
        return false;
    int x;
    x = s.data[s.top]; //将栈顶元素值赋给x
    s.top = s.top - 1;
    return x;
}

//读取栈顶元素
bool GetTop(sqstack s,int x){
    if(s.top == -1)
        return false;
    x = s.data[s.top];
    return true;
}