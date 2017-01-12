
#include <stdio.h>
#include <stdlib.h>
#include <Status.h>
#include <LinkList.h>

int main(){

    return 0;
}

//得到序列元素的值2.9
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

//插入某个书数据到序列号2.10
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

//删除列表的第i个的元素,并且返回这个元素
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

//创建List列表2.11
Status CreateList_L(LinkList L,int n){
    //创建头节点
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    for(int i = n;i<n;i++){
        //创建一个新的的节点
        LinkList p = (LinkList)malloc(sizeof(LNode));
        scanf("",&p->data);
        p->next = L->next;
        L->next = p;
    }
}

//按照顺序合并List列表2.12
Status MergeList_L(LinkList La,LinkList Lb,LinkList Lc){
    //首先将Lc列表初始化为La
    Lc = La;
    LinkList pa = La->next;
    LinkList pb = Lb->next;
    LinkList pc = Lc;
    while(pa&&pb){
        if(pa->data<=pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pb : pa;
    free(La);
    free(Lb);
}
