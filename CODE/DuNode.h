#include <stdio.h>
#include <stdlib.h>
#include <Status.h>

typedef struct DuLNode{
    ElemType data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode,*DuLinkList;


