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

//行编辑器程序
void lineEdit(){
    printf("***********************行编辑器***********************\n");
    SqStack S;
    InitStack(&S);
    char ch = getchar();
    while(ch!= EOF){
        while(ch!=EOF&&ch!='\n'){
            SElemType e;
            switch(ch){
            case '#':
                Pop(&S,e);
                break;
            case '@':
                ClearStack(&S);
                break;
            default :
                Push(&S,ch);
                break;
            }
            ch = getchar();
        }
        //将获得的栈内的数据存放到区域
        PrintStack(S);
        ClearStack(&S);
        if(ch!=EOF){
            ch = getchar();
        }
    }
    DestoryStack(&S);
    printf("***********************行编辑器***********************\n");
}

//表达式求解
void MazeType(){
    //
}

//栈的测试
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
        lineEdit();
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


