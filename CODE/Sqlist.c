#include <stdio.h>
#include <stdlib.h>
#include <Status.h>
#include <Sqlist.h>

#define LIST_INIT_SIZE  100
#define LISTINCREAMENT  10

Status InitList_Sq(Sqlist *L){
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(L->elem){
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}

Status ListInsert_Sq(Sqlist *L,int i,ElemType e){
    //判断插入位置是否合法
    if(i<1||i>L->length+1){
        return ERROR;
    }
    if(L->length >= L->listSize){
        L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        ElemType* newbase = (ElemType*)realloc(L->elem,sizeof(ElemType)*(L->listSize+LISTINCREAMENT));
    }
    return OK;
}

int main(){
    Sqlist L;
    InitList_Sq(&L);
    ListInsert_Sq(&L,0,23);
    return 0;
}

