
#include <stdio.h>
#include <stdlib.h>
#include <SqQueue.h>

//��ʼ��ѭ���б�
Status InitSqQueue(SqQueue Q){
    Q.base = (QElemType *)malloc(sizeof(QElemType));
    if(!Q.base){
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
    return OK;
}

//����ѭ���б�ĳ���
int SqQueueLength(SqQueue Q){
    return (Q.rear-Q.front+MAXQSIE)%MAXQSIE;
}

//����Ԫ��
Status EnSqQueue(SqQueue Q,QElemType e){
    if((Q.rear+1)/MAXQSIE == Q.front){
        //��������
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXQSIE;
    return OK;
}

//ɾ�����е����һ��Ԫ��
Status DeSqQueue(SqQueue Q,QElemType e){
    if(Q.rear == Q.front){
        return ERROR;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front+1)%MAXQSIE;
    return OK;
}

int main(){
    //
}
