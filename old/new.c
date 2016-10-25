#include <stdio.h>
#include <string.h>

int main(){
    struct person{
        int number;
        char name[20];
        char sex;
        float weight;
    }stu[3] = {{1001,"kouzi",'m',65.6},{1002,"elon",'w',66},{1003,"kou",'m',67}};
    struct person *pt;
    for(pt = stu;pt < stu+3;pt++){
        printf("number:%6d",pt->number);
        printf("name:%6s",pt->name);
        printf("sex:%6c",pt->sex);
        printf("weight:%6.2f",pt->weight);
        printf("\n");
    }
    return 0;
}
