    #include <stdio.h>
int a[][3] = {{1,2,3},{4,5,6},{7,8,9}};
//int b[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
int b[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
char c[] = "I am elonkou.";
char *d = "I am a student.";

int main(){
    void printfB();
    void printfC();
    void copyStr(char *c,char *d);
    void max(int x,int y);
    int min(int x,int y);
    void (*bo)(int x,int y);
    bo = max;
    (*bo)(333,222);

    printf("\n***********************\n");    printf("%d\n",a);
    printf("%d\n",a[0]);
    printf("%d\n",*(a+0));
    printf("%d\n",a+1);
    printf("%d\n",a[0]+1);
    printf("%d\n",a[0][0]+1);
    printf("\n***********************\n");

    printfB();
    printfC();
    copyStr(c,d);

    return 0;
}

//数组元素指针作为形式参数传入
void printfB(){
    printf("\n***********************\n");
    int *p;
    for(p=b[0];p<b[0]+12;p++){
        if((p-b[0])%4==0){
            printf("\n");
        }
        printf("%4d",*p);
    }
    printf("\n***********************\n");
}

//二维数组参数
void printfC(){
    printf("\n***********************\n");
    int (*pp)[4] = b;
    int i,j;
    printf("Input i,j\n");
    scanf("%d,%d",&i,&j);
    printf("%d",*(*(pp+i)+j));
    printf("\n***********************\n");
}

//指针操作字符串
void copyStr(char *c,char *d){
    printf("\n************printfStr***********\n");
    while(*c!='\0'){
        printf("%c",*c);
        c++;
    }
    printf("\n");
    do{
        printf("%c",*d);
        d++;
    }while(*d!='\n');
    d--;
    d--;
    printf("%d",*d);    printf("\n***********************\n");
}

//指针函数表现
void max(int x,int y){
    int maa = x;
    printf("\n***********************\n");
    maa = x>y?x:y;
    printf("%d",maa);
    printf("\n***********************\n");
}

