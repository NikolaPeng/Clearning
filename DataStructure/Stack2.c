//链栈:用链式存储方式实现的栈
//规定单链表只能在一端实现插入和删除的操作（头插法），将链头看作栈顶
//基本操作；初始化、出栈、进栈、获取栈顶元素、判断栈空、满
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//定义一个链栈
typedef struct LinkStack{
    int data;
    struct LinkStack * next;
}LinkStack;

//初始化
bool InitLinkStack(LinkStack *L){
    L = NULL;
    return true;
}

//进栈操作
LinkStack *push(LinkStack *stack,int x){
    LinkStack *L;
    L = (LinkStack *)malloc(sizeof(LinkStack));
    L->data = x;
    L->next = stack;
    stack = L;
    return stack;
}

//出栈操作
LinkStack *pop(LinkStack *stack){
    if(stack){
        LinkStack *p = stack;
        stack  = stack->next;
        printf("弹栈元素:%d ",p->data);

        if(stack){
            printf("栈顶元素%d\n",stack->data);
        }else{
            printf("栈已空\n");
        free(p);
        }
    }else{
        printf("栈已空\n");
        return stack;
    }  
    return stack;
}
int main(void){
    LinkStack *s=NULL;
    
    s = push(s,0);
    s = push(s,2);
    s = push(s,22);
    s = pop(s);
    s = pop(s);
    s = pop(s);
    return 0;
}