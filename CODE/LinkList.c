#include <stdint.h>
#include <stdlib.h>
#include <Status.h>
#include <LinkList.h>

int main(){

    return 0;
}

//�õ�����Ԫ�ص�ֵ2.9
Status GetElem_L(LinkList L,int i,ElemType e){
    LinkList p = L->next;
    int j = 0;
    while(p&&j<i){
        p = p->next;
        ++j;
    }
    if(!p||j>i){
        return ERROR;
    }
    e = p->data;
    return OK;
}

//����ĳ�������ݵ����к�2.10
Status ListInsert_L(LinkList L,int i,ElemType e){
    LinkList p = L;
    int j = 0;
    while(p&&j<i-1){
        p = p->next;
        ++j;
    }
    if(!p||j>i-1){
        return ERROR;
    }
    LinkList s = (LinkList)malloc(sizeof(ElemType));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
