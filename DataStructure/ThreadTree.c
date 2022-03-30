//三种线索二叉树
//二叉树线索化
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
//线索二叉树就是利用n+1个空链域来存放节点的前驱和后继节点信息
//我们把空指针域的left指向前驱，right指向后继。
//在每一个节点都增设bool型变量Ltag和Rtag，它们为1时指向前驱/后继。

typedef struct TreadNode{
    int data;
    struct TreadNode *lchild, *rchild;
    int ltag, rtag;
}*TreadTree, TreadNode;

TreadNode *pre = NULL;
//中序遍历线索二叉树，一边遍历一边将其线索化。
void visitTree(TreadNode *q){
    if(q->lchild==NULL){    //左子树为空，建立前驱线索；
        q->lchild = pre;
        q->ltag = 1;
    }
    if(pre!=NULL&&pre->rchild==NULL){
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}
void InTread(TreadTree T){
    if(T!=NULL){
        InTread(T->lchild);
        visitTree(T);
        InTread(T->rchild);
    }
}

void CreateInTread(TreadTree T){
    pre = NULL;
    if(T!=NULL){
        InTread(T);
        if(pre->rchild==NULL)
            pre->rtag = 1;
    }
}