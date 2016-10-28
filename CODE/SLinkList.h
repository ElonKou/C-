#include <stdio.h>
#include <Status.h>
#define MAXSIZE 1000

typedef struct{
    ElemType data;
    int cur;
}compoent,SLinkList[MAXSIZE];

//定位静态单链表L中的第一个值为e的元素2.13
int LocateElem_SL(SLinkList S,ElemType e);

//初始化列表2.14
void InitSpace_SL(SLinkList space);

//如果备用链表为空，放回分配的节点下标，否则返回0 2.14
int malloc_SL(SLinkList space);

//释放SL，将下标为k的空闲节点回收到备用链表2.15
void Free_SL(SLinkList space,int k);
