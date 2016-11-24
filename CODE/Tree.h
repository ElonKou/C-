#include <Status.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//һ��˳������ṹ
//#define MAX_TREE_SIZE   100
//typedef TElemType SqBiTree[MAX_TREE_SIZE];
//SqBiTree bt;

//����������ʽ�����ṹ
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *rchild, *lchild;
}BiTNode,*BiTree;


void InitBiTree(BiTree T){
    //��ʼ���ڵ�
    T = NULL;
}

void ClearBiTree(BiTree T){
    //�����
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
    //�������ṹ������ÿ�ε�����
    int ch;
    printf("��ʼ�������ִ������ṹ\n");
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
    printf("����û���ӽڵ�\n");
    return T;
}

void PreOrderTree(BiTree T){
    //���������
    if(T){
        printf(" %d ",T->data);
        PreOrderTree(T->lchild);
        PreOrderTree(T->rchild);
    }else{
        printf(" * ");
    }
}

void InOrderTree(BiTree T){
    //���������
    if(T){
        InOrderTree(T->lchild);
        printf(" %d ",T->data);
        InOrderTree(T->rchild);
    }else{
        printf(" * ");
    }
}

void PosOrderTree(BiTree T){
    //���������
    if(T){
        PosOrderTree(T->lchild);
        PosOrderTree(T->rchild);
        printf(" %d ",T->data);
    }else{
        printf(" * ");
    }
}

int BiTreeDepth(BiTree T){
    //�����������
    int LD,RD;
    if(!T){
        return 0;
    }else{
        LD = BiTreeDepth(T->lchild);
        RD = BiTreeDepth(T->rchild);
        return (LD>RD?LD:RD)+1;
    }
}

