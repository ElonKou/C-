#include <stdio.h>
#include <stdlib.h>
#include <SqQueue.h>

//初始化循环列表
Status InitSqQueue(SqQueue Q){
    Q.base = (QElemType *)malloc(sizeof(QElemType));
    if(!Q.base){
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
    return OK;
}

//返回循环列表的长度
int SqQueueLength(SqQueue Q){
    return (Q.rear-Q.front+MAXQSIE)%MAXQSIE;
}

//插入元素
Status EnSqQueue(SqQueue Q,QElemType e){
    if((Q.rear+1)/MAXQSIE == Q.front){
        //队列满了
        return ERROR;
    }
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear+1)%MAXQSIE;
    return OK;
}

//删除队列的最后一个元素
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
