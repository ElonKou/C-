#include <stdio.h>

int main(){

    struct Date{
        int year;
        int month;
        int day;
    };

    struct student{
        char name[20];
        int age;
        char sex;
        float weight;
        struct Date birth;
    };
    struct student stu = {"elon kou",21,'M',66,{1995,1,2}};
    printf("Name:%s\n",stu.name);
    printf("Age:%d\n",stu.age);
    printf("Sex:%c\n",stu.sex);
    printf("Weight:%.2f\n",stu.weight);
    printf("Year:%d\n",stu.birth.year);
    printf("Month:%d\n",stu.birth.month);
    printf("Day:%d\n",stu.birth.day);


    return 0;
}
