#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//�õ�����Ԫ�ص�ֵ2.9
Status GetElem_L(LinkList L,int i,ElemType e);

//����ĳ�������ݵ����к�2.10
Status ListInsert_L(LinkList L,int i,ElemType e);

//����List�б�2.11
Status CreateList_L(LinkList L,int n);

//����˳��ϲ�List�б�2.12
Status MergeList_L(LinkList La,LinkList Lb,LinkList Lc)