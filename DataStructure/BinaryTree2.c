//二叉树的链式存储及操作
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define Max 100

#include "Queue2.c"
//定义一个二叉树
typedef struct BiTNode{
    char data;
    struct BiTNode *left,*right;
}BiTNode,*BiTree;

//初始化
bool InitBiTree(BiTree *T){
    *T=NULL;
    return true;
}
//判断是否为空
bool BiTreeIsEmpty(BiTree T){
    if(T==NULL)
        return true;
    else
        return false;
}
//创建链二叉树(递归)
typedef char String[Max];
String S;
int i=1;
void createBiTree(BiTree T){
    int num;
    num = S[i++];
    if(num == '#')
        T = NULL;
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        if(!T)
            printf("内存分配失败\n");
        else
            T->data = num;
        createBiTree(T->left);
        createBiTree(T->right);
    }
}
//销毁链二叉树（递归）
void deleteBiTree(BiTree T){
    if(T){
        if(T->left){
            deleteBiTree(T->left);
        }
        if(T->right){
            deleteBiTree(T->right);
        }
    }
    free(T);
    T =NULL;
}
//获得深度(递归)
int getDepth(BiTree T){
    int depth = 0;
    if(T==NULL){
        return -1;
    }else{
        int leftDepth = getDepth(T->left);
        int rightDepth = getDepth(T->right);
        depth = leftDepth>rightDepth?leftDepth+1:rightDepth+1;
    }
    return depth;
}
//获得某节点数据
int getData(BiTree T){
    if(T==NULL)
        return -1;
    else 
        return T->data;
}
//四种遍历方法
//前序
void preOrderTraverse(BiTree T){
    if(T==NULL)
        return;
    printf("%d",T->data);
    preOrderTraverse(T->left);
    preOrderTraverse(T->right);
}
//中序,后序 同理

//层次遍历
/*
思想：
1、初始化一个辅助队列；
2、根节点入队；
3、若队列非空，则根节点出队，并访问该节点；之后队尾插入该节点的左孩子和右孩子
4、重复操作3直到队列为空。
*/
void levelOrderTraverse(BiTree T){
    LinkQueue Q; 
    InitLinkQueue1(Q); //初始化队列
    BiTree p; //初始化树
    EnLinkQueue1(Q,T->data); //根节点入队
    while(!LQueueIsEmpty(Q)){ //队列非空判断
        DeLinkQueue1(Q,p->data); //队头节点出队，赋给p
        printf("%d ",p->data); //访问p
        if(T->left!=NULL)
            EnLinkQueue1(Q,T->left->data);
        if(T->right!=NULL)
            EnLinkQueue1(Q,T->right->data);
    }
}
