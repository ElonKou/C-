#include <stdio.h>
#include <SqStack.h>

void conversion(){
    printf("***********************����ת��***********************\n");
    SqStack S;
    InitStack(&S);
    int N;
    printf("������ʮ��������\n");
    scanf("%d",&N);
    printf("������Ϊ:");
    while(N){
        Push(&S,N%2);
        N/=2;
    }
    if(!EmptyStack(S)){
        PrintStack(S);
    }
    printf("***********************����ת��***********************\n");
}

//ջ�Ĳ���--�����Ƶ�ת��
int main(){
    printf("��ѡ����õĺ���\n");
    printf("1.����ת��:\n");
    printf("2.����ת��:\n");
    printf("3.����ת��:\n");
    printf("4.����ת��:\n");
    int key ;
    scanf("%d",&key);
    switch (key){
    case 1:
        conversion();
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
    return 0;
}


