#include <Status.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

//����ջ���͵Ľṹ��
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
