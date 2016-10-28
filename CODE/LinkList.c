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
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

//ɾ���б�ĵ�i����Ԫ��,���ҷ������Ԫ��
Status ListDelete_L(LinkList L,int i,ElemType e){
    LinkList p = L;
    int j = 0;
    while(p->next&&j<i-1){
        p =p->next;
        ++j;
    }
    if(!(p->next)||j>i-1){
            return ERROR;
    }
    LinkList q = p->next;
    p->next  = q->next;
    e = q->data;
    free(q);
    return OK;
}

//����List�б�
Status CreateList_L(LinkList L,int n){
    //����ͷ�ڵ�
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for(int i = n;i<n;i++){
        //����һ���µĵĽڵ�
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("",&p->data);
        p->next = L->next;
        L->next = p;
    }
}

