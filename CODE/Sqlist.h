#include <stdio.h>
#include <Status.h>

#define LIST_LIST_SIZE  100
#define LISTINCREAMENT  10

typedef struct{
    ElemType *elem;
    int length;
    int listSize;
}Sqlist;

//�����ʼ��
Status InitList_Sq(Sqlist *L);
//����ڵ�
Status ListInsert_Sq(Sqlist *L,int i,ElemType e);
//ɾ��һ���ڵ������,��e����ɾ��������
Status ListDelete_Sq(Sqlist *L,int i,ElemType e);
//����һ���ڵ����ֵ
int LocateElem_Sq(Sqlist L,ElemType e,Status (* compare)(ElemType,ElemType));
//�ϲ�����
void MergeList_Sq(Sqlist La,Sqlist Lb,Sqlist *Lc);
