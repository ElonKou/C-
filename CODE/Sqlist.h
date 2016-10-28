#include <stdio.h>
#include <Status.h>

#define LIST_LIST_SIZE  100
#define LISTINCREAMENT  10

typedef struct{
    ElemType *elem;
    int length;
    int listSize;
}Sqlist;

//链表初始化
Status InitList_Sq(Sqlist *L);
//插入节点
Status ListInsert_Sq(Sqlist *L,int i,ElemType e);
//删除一个节点的数据,用e返回删除的数据
Status ListDelete_Sq(Sqlist *L,int i,ElemType e);
//查找一个节点的数值
int LocateElem_Sq(Sqlist L,ElemType e,Status (* compare)(ElemType,ElemType));
//合并链表
void MergeList_Sq(Sqlist La,Sqlist Lb,Sqlist *Lc);
