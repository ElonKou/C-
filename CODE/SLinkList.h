#include <stdio.h>
#include <Status.h>
#define MAXSIZE 1000

typedef struct{
    ElemType data;
    int cur;
}compoent,SLinkList[MAXSIZE];

//��λ��̬������L�еĵ�һ��ֵΪe��Ԫ��2.13
int LocateElem_SL(SLinkList S,ElemType e);

//��ʼ���б�2.14
void InitSpace_SL(SLinkList space);

//�����������Ϊ�գ��Żط���Ľڵ��±꣬���򷵻�0 2.14
int malloc_SL(SLinkList space);

//�ͷ�SL�����±�Ϊk�Ŀ��нڵ���յ���������2.15
void Free_SL(SLinkList space,int k);
