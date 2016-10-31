#include <Status.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

//定义栈类型的结构体
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
