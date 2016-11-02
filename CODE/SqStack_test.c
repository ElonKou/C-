#include <stdio.h>
#include <SqStack.h>

void conversion(){
    printf("***********************数制转换***********************\n");
    SqStack S;
    InitStack(&S);
    int N;
    printf("请输入十进制数字\n");
    scanf("%d",&N);
    printf("二进制为:");
    while(N){
        Push(&S,N%2);
        N/=2;
    }
    if(!EmptyStack(S)){
        PrintStack(S);
    }
    printf("***********************数制转换***********************\n");
}

//栈的测试--二进制的转换
int main(){
    printf("请选择调用的函数\n");
    printf("1.数制转换:\n");
    printf("2.数制转换:\n");
    printf("3.数制转换:\n");
    printf("4.数制转换:\n");
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


