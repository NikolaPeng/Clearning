//二叉树：根节点、左子树、右子树
//满二叉树
//完全二叉树
//二叉排序树
//平衡二叉树：有更高的搜索效率
//二叉树的遍历*

//1、顺序实现：
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define Max 100

typedef struct{
    int value;
    bool isEmpty;
}TreeNode;
TreeNode BiTree[Max];

//初始化一个二叉树：
bool InitBiTree(TreeNode T[]){
    for(int i=0;i<Max;i++){
        T[i].isEmpty = true;
    }
    printf("二叉树初始化完成.\n");
    return true;
}
//清空二叉树
#define ClearBiTree InitBiTree
//创建一个二叉树
bool CreateBiTree(TreeNode T[]){
    printf("创建一个存储数据是0-Max的树\n");
    int data=0;
    for(int i=0;i<Max;i++){
        T[i].value = data;
        data++;
    }
    return true;
}
//判断一个二叉树是否为空
bool TreeisEmpty(TreeNode T[]){
    if(T[0].isEmpty)
        return true;
    else 
        return false;
}
//获取二叉树根节点数据:
int getRoot(TreeNode T[]){
    if(TreeisEmpty(T)){
        return -1;
        printf("空\n");
    }
    int e = T[0].value;
    return e;
}
//获取二叉树节点e的parent：（i+1）/2向下取整
int getParent(TreeNode T[],int e){
    if(TreeisEmpty(T))
        return -1;
    int m;
    for(int i=0;i<Max;i++){
        if(T[i].value==e){
            m = (int)floor((i+1)/2);
            return T[m].value;
        }
    }
    return -1;
}
//获取某个节点的leftchild：2i+1
int getLeftChild(TreeNode T[],int e){
    if(TreeisEmpty(T))
        return -1;
    int m;
    for(int i=0;i<Max;i++){
       if(T[i].value==e){
            m = 2*i+1;
            return T[m].value;
        } 
    }
    return -1;
}
//获取rightchild ：2i+2
int getRightChild(TreeNode T[],int e){
    if(TreeisEmpty(T))
        return -1;
    int m;
    for(int i=0;i<Max;i++){
       if(T[i].value==e){
            m = 2*i+2;
            return T[m].value;
        } 
    }
    return -1;
}

//---------二叉树的遍历-------------

//前序访问输出
void preOrderVisit(TreeNode T[],int now){
    printf("%d ",T[now].value);
    if(!T[now*2+1].isEmpty)
        preOrderVisit(T,now*2+1);
    if(!T[now*2+2].isEmpty)
        preOrderVisit(T,now*2+2); 
}
//前序遍历
bool preOrderTraverse(TreeNode T[]){
    if(TreeisEmpty(T))
        return false;
    preOrderVisit(T,0);
    printf("\n");
    return true;
}
//中序访问输出
void inOrderVisit(TreeNode T[],int now){
    if(!T[now*2+1].isEmpty)
        preOrderVisit(T,now*2+1);
    printf("%d ",T[now].value); 
    if(!T[now*2+2].isEmpty)
        preOrderVisit(T,now*2+2);  
}
//中序遍历
bool inOrderTraverse(TreeNode T[]){
    if(TreeisEmpty(T))
        return false;
    inOrderVisit(T,0);
    printf("\n");
    return true;
}
//后续访问输出
void posOrderVisit(TreeNode T[],int now){
    if(!T[now*2+1].isEmpty)
        preOrderVisit(T,now*2+1);
    if(!T[now*2+2].isEmpty)
        preOrderVisit(T,now*2+2); 
    printf("%d ",T[now].value);  
}
//后序遍历
bool posOrderTraverse(TreeNode T[]){
    if(TreeisEmpty(T))
        return false;
    posOrderVisit(T,0);
    printf("\n");
    return true;
}

//获取二叉树的深度

//层次遍历
