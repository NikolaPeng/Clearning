#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
//二叉排序树：左子树结点值<根结点值<右子树结点值
typedef struct BSTNode{
	int key;
    struct BSTNode *lchild,*rchild;
    }BSTNode,*BSTree;

//查找效率取决于树的高度；最优是O(logN),最差是O(N)
//在二叉排序树中查找值为key的结点:1
BSTree BSTSearch(BSTree T,int key){
    while(T!=NULL&&T->key!=key){
        if(T->key<key)
            return T->rchild;
        else
            return T->lchild;
    }
    return T;
}

//2.递归实现
BSTree BSTSearch2(BSTree T,int key){
    if(T==NULL)
        return NULL;
    if(T->key == key)
        return T;
    else if(T->key < key)
        return BSTSearch2(T->rchild,key);
    else 
        return BSTSearch2(T->lchild,key);
}

//二叉排序树的插入
int BSTInsert(BSTree T,int k){
    if(T==NULL){
        T = (BSTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild =NULL;
        return 1;
    }
    else if(T->key == k){
        return 0;
    }
    else if(k<T->key){
        return BSTInsert(T->lchild,k);
    }
    else{
        return BSTInsert(T->rchild,k);
    }
}

//二叉排序树的构造
void CreateBSTree(BSTree T,int str[],int n){
    T = NULL;
    int i = 0;
    if(i<n){
        BSTInsert(T,str[i]);
        i++;
    }
}

//删除操作
/*
1、先搜索找到要被删除的目标结点；
2、如果该节点是叶子节点，则直接删除；
3、若节点k只有一棵左子树或右子树，则让该节点k的子树成为k父节点的子树，代替其位置。
4、若节点k有左右两颗子树，则令k的直接后继/前驱代替k，
   然后从二叉树中删除该直接后继/前驱，这样就将问题转化为前俩种情况了。
*/
bool Delete(BSTree T){
    
}

bool DeleteBSTree(BSTree T,int k){
    if(!T){
        return false;
    }else{
        if(k==T->key)
            return Delete(T);
        else if(k<T->key)
            return DeleteBSTree(T->lchild,k);
        else
            return DeleteBSTree(T->rchild,k);
    }
}

