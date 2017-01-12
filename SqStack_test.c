
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

//�б༭������
void lineEdit(){
    printf("***********************�б༭��***********************\n");
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
        //����õ�ջ�ڵ����ݴ�ŵ�����
        PrintStack(S);
        ClearStack(&S);
        if(ch!=EOF){
            ch = getchar();
        }
    }
    DestoryStack(&S);
    printf("***********************�б༭��***********************\n");
}

//���ʽ���
void MazeType(){
    //
}

//ջ�Ĳ���
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


