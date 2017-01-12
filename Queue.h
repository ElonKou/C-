
#include <Status.h>

//定义新的链队列元素
typedef struct{
    QElemType data;
    struct QNode *next;
}QNode;

//定义新的链队列
typedef struct {
    QNode *front;
    QNode *rear;
}LinkQueue;
