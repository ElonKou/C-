#include <stdio.h>
#include <stdlib.h>
#include <Status.h>
#include <SLinkList.h>

int main(){
    return 0;
}

//定位静态单链表L中的第一个值为e的元素2.13
int LocateElem_SL(SLinkList S,ElemType e){
    int i = S[0].cur;
    while(i&&S[i].data != e){
        i = S[i].cur;
    }
    return i;
}

//初始化列表2.14
void InitSpace_SL(SLinkList space){
    for(int i = 0;i<MAXSIZE-1;++i){
        space[MAXSIZE-1].cur = 0;
    }
}

//如果备用链表为空，放回分配的节点下标，否则返回0 2.14
int malloc_SL(SLinkList space){
    int i = space[0].cur;
    if(space[i].cur){
        space[0].cur = space[i].cur;
    }
    return i;
}

//释放SL，将下标为k的空闲节点回收到备用链表2.15
void Free_SL(SLinkList space,int k){
    space[k].cur = space[0].cur = k;
}



