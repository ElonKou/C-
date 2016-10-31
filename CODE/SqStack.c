#include <stdio.h>
#include <stdlib.h>
#include <Status.h>
#include <SqStack.h>

//��ʼ��ջ
Status InitStack(SqStack *S){
    S->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S->base){
        return OVERFLOW;
    }
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//�õ�ջ��������
Status GetTop(SqStack *S,SElemType e){
    if(S->top==S->base){
        return ERROR;
    }
    e = *(S->top-1);
    return OK;
}

//��ջ����
Status Push(SqStack *S,SElemType e){
    if(S->base-S->top>=S->stacksize){
        //�ȿ����Ƿ񳬳�ջ�����ݵ�����
        S->base = (SElemType *)realloc(S->base,(STACKINCREMENT+S->stacksize)*sizeof(SElemType));
        if(!S->base){
            exit(OVERFLOW);
        }
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top ++= e;
}

//��ջ����
Status Pop(SqStack *S,SElemType e){
    if(S->base==S->top){
        return ERROR;
    }
    e = *--S->top;
    return OK;
}

//����ջ
Status DestoryStack(SqStack *S){
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stacksize = 0;
    return OK;
}

//���ջ
Status ClearStack(SqStack *S){
    S->top = S->base;
    return OK;
}

//�ж�ջ�ǲ���Ϊ��
Status EmptyStack(SqStack S){
    if(S.base == S.top){
        return TRUE;
    }
    return FALSE;
}

//����ջ�ĳ���
int StackLength(SqStack S){
    return S.top-S.base;
}

//����ջ����ִ��ĳ������
Status StackTraverse(SqStack S,Status (*visit)()){
    //������ʱ���ԭջ�ı���
    SElemType *p = S.base;
    while(p<S.top){
        visit(*p++);
    }
    return OK;
}

int main(){
    return 0;
}



