
#include <Status.h>

//�����µ�������Ԫ��
typedef struct{
    QElemType data;
    struct QNode *next;
}QNode;

//�����µ�������
typedef struct {
    QNode *front;
    QNode *rear;
}LinkQueue;
