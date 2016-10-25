#include <stdio.h>
#include <stdlib.h>
#include <Status.h>
#include <Sqlist.h>

#define LIST_INIT_SIZE  100
#define LISTINCREAMENT  10

//��ʼ���б�
Status InitList_Sq(Sqlist *L){
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(L->elem){
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}

//����һ���ڵ�
Status ListInsert_Sq(Sqlist *L,int i,ElemType e){
    //�жϲ���λ���Ƿ�Ϸ�
    if(i<1||i>L->length+1){
        return ERROR;
    }
    if(L->length >= L->listSize){
        //L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        ElemType* newbase = (ElemType*)realloc(L->elem,sizeof(ElemType)*(L->listSize+LISTINCREAMENT));
        if(!newbase){
            exit(ERROR);
        }
        int q = &(L->elem[i-1]);
    }

    return OK;
}

//�õ�һ���ڵ������


int main(){
    Sqlist L;
    ElemType e;
    InitList_Sq(&L);
    ListInsert_Sq(&L,0,23);
    ListInsert_Sq(&L,1,32);
    ListInsert_Sq(&L,2,555);
    printf("L1:%d",L.elem);
    return 0;
}

