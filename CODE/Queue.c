#include <stdio.h>
#include <stdlib.h>
#include <Queue.h>

//��ʼ��������
Status InitQueue(LinkQueue Q){
    Q.front = Q.rear = (QNode *)malloc(sizeof(QNode));
    if(!Q.front){
        exit(OVERFLOW);
    }
    Q.front = Q.rear = NULL;
    return OK;
}

//����������
Status DestoryQueue(LinkQueue Q){
    while(Q.front){
        Q.rear = (QNode*)Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return ERROR;
}

//�������
Status EnQueue(LinkQueue *Q,QElemType e){
    QNode *p = (QNode *)malloc(sizeof(QNode));
    if(!p){
        return OVERFLOW;
    }
    p->data = e;
    p->next = NULL;
    (QNode*)Q->rear->next = p;
    Q->rear = p;
    return OK;
}

//ɾ��Ԫ��
Status DeQueue(LinkQueue *Q,QElemType e){
    //�ж������ǲ���Ϊ��
    if(Q->front == Q->rear){
        return ERROR;
    }
    QNode *p = (QNode*)Q->front->next;
    e = p->data;
    Q->front->next = p->next;
    if(Q->rear==p){
        Q->rear = Q->front;
    }
    free(p);
}

int main(){
    //
    return 0;
}
