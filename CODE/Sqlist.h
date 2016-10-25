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
//清空列表
ClearList_Sq(Sqlist *L);
//销毁列表
Status DestoryList_Sq(Sqlist *L);
