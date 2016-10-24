#include <stdio.h>

int x=3,y=5;

int main(){
    int max(int x,int y);
    int min(int x,int y);
    void printLine();
    int x=3,y=5;
    int ax = max(x,y);
    int in = min(x,y);

    printLine("main");
    printf("max=%d\n",ax);
    printf("min=%d",in);
    printLine("main");

    void func(int (*f1)(int,int),int (*f2)(int,int));
    int (*f1)(int x,int y);
    int (*f2)(int x,int y);
    f1 = max;
    f2 = min;
    func(f1,f2);

    //返回指针测试
    int fanhui(int (*p)[4],int n);
    int cc[][4]={{1,2,3,4},{11,12,13,14},{21,22,23,24}};
    printLine("fanhui");
    printf("%d",fanhui(cc,2));
    printLine("fanhui");

    return 0;
}


//最大值
int max(int x,int y){
    return x>y?x:y;
}

//最小值
int min(int x,int y){
    return x<y?x:y;
}

//打印一行星
void printLine(char str[]){
    printf("\n********************%s********************\n",str);
}

//参数为指针函数
void func(int (*f1)(int,int),int (*f2)(int,int)){
    printLine("func");
    int ff1 = (*f1)(x,y);
    int ff2 = (*f2)(x,y);
    printf("max of %d %d:%d\n",x,y,ff1);
    printf("min of %d %d:%d",x,y,ff2);
    printLine("func");
}

//返回指针类型
int fanhui(int (*p)[4],int n){
    int *pos;
    pos = *(p+n);
    return pos;
}
