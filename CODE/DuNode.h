#include <stdio.h>
#include <stdlib.h>
#include <Status.h>

typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;

Status ListInsert_DuL(DuLinkList L,int i,ElemType e){
    if(!(GetElem_DuL(L,i))){

    }
}
