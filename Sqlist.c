#include <stdio.h>
#include <stdlib.h>
#include <Status.h>
#include <Sqlist.h>

#define LIST_INIT_SIZE  100
#define LISTINCREAMENT  10

//初始化列表
Status InitList_Sq(Sqlist *L){
    L->elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(L->elem){
        exit(OVERFLOW);
    }
    L->length = 0;
    L->listSize = LIST_INIT_SIZE;
    return OK;
}

//插入一个节点
Status ListInsert_Sq(Sqlist *L,int i,ElemType e){
    //判断插入位置是否合法
    if(i<1||i>L->length+1){
        return ERROR;
    }
    if(L->length >= L->listSize){
        //L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
        ElemType * newbase = (ElemType*)realloc(L->elem,sizeof(ElemType)*(L->listSize+LISTINCREAMENT));
        if(!newbase){
            exit(ERROR);
        }
        L->listSize += LISTINCREAMENT;
    }
    ElemType *q = &(L->elem[i-1]);
    for(ElemType *p = &(L->elem[L->length-1]);p >= q;--p){
            *(p+1) = *p;
        }
    *q = e;
    ++L->length;
    return OK;
}

//删除一个节点的数据,用e返回删除的数据
Status ListDelete_Sq(Sqlist *L,int i,ElemType e){
    if(i<=0||i>(L->length)){
        return ERROR;
    }
    ElemType *p = &(L->elem[i-1]);
    e = *p;
    ElemType *q = &(L->elem[L->length-1]);
    for(p;p<=q-1;++p){
        *p = *(p+1);
    }
    --L->length;
    return OK;
}

//查找一个节点的数值
int LocateElem_Sq(Sqlist L,ElemType e,Status (* compare)(ElemType,ElemType)){
    int i = 1;
    ElemType *p = L.elem;
    while(i<=L.length&&!(*compare)(*p++,e)){
        ++i;
    }
    if(i<L.length){
            return i;
    }else{
        return 0;
    }
}

//合并链表
void MergeList_Sq(Sqlist La,Sqlist Lb,Sqlist *Lc){
    ElemType *pa = La.elem;
    ElemType *pb = Lb.elem;
    Lc->listSize = Lc->length = La.length+Lb.length;
    ElemType *pc = Lc->elem = (ElemType *)malloc(Lc->listSize*sizeof(ElemType));
    if(!pc){
        exit(OVERFLOW);//内存分配失败
    }
    ElemType *pa_last = La.elem+(La.length-1);
    ElemType *pb_last = Lb.elem+(Lb.length-1);
    while(pa<=pa_last&&pb<=pb_last){
        if(*pa<=*pb){
            *pc++=*pa++;
        }else{
            *pc++=*pb++;
        }
    }
    while(pa<=pa_last){
        *pc++=*pa++;
    }
    while(pb<=pb_last){
        *pc++=*pb++;
    }
}


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


