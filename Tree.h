#include <Status.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//一：顺序存贮结构
//#define MAX_TREE_SIZE   100
//typedef TElemType SqBiTree[MAX_TREE_SIZE];
//SqBiTree bt;

//二：创建链式存贮结构
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *rchild, *lchild;
}BiTNode,*BiTree;


void InitBiTree(BiTree T){
    //初始化节点
    T = NULL;
}

void ClearBiTree(BiTree T){
    //清空树
    if(T){
        if(T->lchild){
            ClearBiTree(T->lchild);
        }
        if(T->rchild){
            ClearBiTree(T->rchild);
        }
    }
}

BiTree CreateBiTree(BiTree T){
    //创建树结构，根据每次的输入
    int ch;
    printf("开始输入数字创建树结构\n");
    scanf("%d",&ch);
    if(ch == 0){
        T = NULL;
    }
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        printf("%d",T);
        if(!T){
            exit(OVERFLOW);
        }
        T->data = ch;
        T->lchild = CreateBiTree(T->lchild);
        T->rchild = CreateBiTree(T->rchild);
    }
    printf("此树没有子节点\n");
    return T;
}

void PreOrderTree(BiTree T){
    //先序遍历树
    if(T){
        printf(" %d ",T->data);
        PreOrderTree(T->lchild);
        PreOrderTree(T->rchild);
    }else{
        printf(" * ");
    }
}

void InOrderTree(BiTree T){
    //中序遍历树
    if(T){
        InOrderTree(T->lchild);
        printf(" %d ",T->data);
        InOrderTree(T->rchild);
    }else{
        printf(" * ");
    }
}

void PosOrderTree(BiTree T){
    //后序遍历树
    if(T){
        PosOrderTree(T->lchild);
        PosOrderTree(T->rchild);
        printf(" %d ",T->data);
    }else{
        printf(" * ");
    }
}

int BiTreeDepth(BiTree T){
    //计算树的深度
    int LD,RD;
    if(!T){
        return 0;
    }else{
        LD = BiTreeDepth(T->lchild);
        RD = BiTreeDepth(T->rchild);
        return (LD>RD?LD:RD)+1;
    }
}


