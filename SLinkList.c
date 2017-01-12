#include <stdio.h>
#include <stdlib.h>
#include <Status.h>
#include <SLinkList.h>

int main(){
    return 0;
}

//��λ��̬������L�еĵ�һ��ֵΪe��Ԫ��2.13
int LocateElem_SL(SLinkList S,ElemType e){
    int i = S[0].cur;
    while(i&&S[i].data != e){
        i = S[i].cur;
    }
    return i;
}

//��ʼ���б�2.14
void InitSpace_SL(SLinkList space){
    for(int i = 0;i<MAXSIZE-1;++i){
        space[MAXSIZE-1].cur = 0;
    }
}

//�����������Ϊ�գ��Żط���Ľڵ��±꣬���򷵻�0 2.14
int malloc_SL(SLinkList space){
    int i = space[0].cur;
    if(space[i].cur){
        space[0].cur = space[i].cur;
    }
    return i;
}

//�ͷ�SL�����±�Ϊk�Ŀ��нڵ���յ���������2.15
void Free_SL(SLinkList space,int k){
    space[k].cur = space[0].cur = k;
}



