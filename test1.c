#include <stdio.h>

int main(){
//定义时间变量
    struct Date{
        int year;
        int month;
        int day;
    };

//定义一个学生的结构体
    struct student{
        int num;
        int age;
        char sex;
        float weight;
        char name[20];
        char addr[32];
        struct Date birthday;
    };
    struct student stu1={1001,21,'m',65.5,"elonkou","usst",{1995,1,2}};
    struct student stu2={.name="kouzi",.age=21};
    printf("size of struct:%d\n",sizeof(struct student));

    printf("num:%d\n",stu1.num);
    printf("age:%d\n",stu1.age);
    printf("sex:%c\n",stu1.sex);
    printf("name:%s\n",stu1.name);
    printf("weight:%f\n",stu1.weight);
    printf("addr:%s\n",stu1.addr);
    printf("birth-year:%d\n",stu1.birthday.year);
    printf("birth-month:%d\n",stu1.birthday.month);
    printf("birth-day:%d\n",stu1.birthday.day);
    return 0;
}


