#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//得到序列元素的值2.9
Status GetElem_L(LinkList L,int i,ElemType e);

//插入某个书数据到序列号2.10
Status ListInsert_L(LinkList L,int i,ElemType e);

//创建List列表2.11
Status CreateList_L(LinkList L,int n);
