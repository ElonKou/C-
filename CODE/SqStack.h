#include <Status.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10

//定义栈类型的结构体
typedef struct{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


//初始化栈
Status InitStack(SqStack *S){
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S->base){
        return OVERFLOW;
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//得到栈顶的数据
Status GetTop(SqStack *S,SElemType e){
    if(S->top==S->base){
        return ERROR;
    }
    e = *(S->top-1);
    return OK;
}

//入栈操作
Status Push(SqStack *S,SElemType e){
    if(S->base-S->top>=S->stacksize){
        //先考虑是否超出栈的内容的请求
        S->base = (SElemType *)realloc(S->base,(STACKINCREMENT+S->stacksize)*sizeof(SElemType));
        if(!S->base){
            exit(OVERFLOW);
        }
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top ++= e;
}

//出栈操作
Status Pop(SqStack *S,SElemType e){
    if(S->base==S->top){
        return ERROR;
    }
    e = *--S->top;
    return OK;
}

//销毁栈
Status DestoryStack(SqStack *S){
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
    return OK;
}

//清空栈
Status ClearStack(SqStack *S){
    S->top = S->base;
    return OK;
}

//判断栈是不是为空
Status EmptyStack(SqStack S){
    if(S.base == S.top){
        return TRUE;
    }
    return FALSE;
}

//返回栈的长度
int StackLength(SqStack S){
    return S.top-S.base;
}

//遍历栈并且执行某个函数
Status StackTraverse(SqStack S,Status (*visit)()){
    //遍历的时候对原栈的保护
    SElemType *p = S.base;
    while(p<S.top){
        visit(*p++);
    }
    return OK;
}

Status PrintStack(SqStack S){
    SElemType *p = S.top;
    SElemType e;
    while(p-->S.base){
        e = *(p);
        printf("%d",e);
    }
    printf("\n");
    return OK;
}
