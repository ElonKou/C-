#define MAXQSIE 100
#include <Status.h>

//循环队列的实现
typedef struct{
    QElemType *base;
    int front;
    int rear;
}SqQueue;
