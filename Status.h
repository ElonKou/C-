#ifndef STATUS_H
#define STATUS_H

/*״̬��*/
#define TRUE    1
#define FALSE   0
#define YES     1
#define No      0
#define OK      1
#define ERROR   0
#define SUCCESS 1
#define UNSUCCESS   0
#define INFEASIBLE  -1

#ifndef _MATH_H_
#define OVERFLOW    -2
#define UNDERFLOW   -3
#endif // _MATH_H_

#ifndef NULL
#define NULL    ((void*)0)
#endif // NULL

/*״̬��ʶ������*/
typedef int Status;

/*�꺯��*/
//������ͣһ��ʱ��
#define Wait(x)\
{\
    double _loop_Num_;\
    for(_loop_Num_=0.01;_loop_Num_<=100000*x;_loop_Num_+=0.01){\
        ;\
    }\
}//����һ����ѭ��

//����Eter������
#define PressEnter()\
{\
    fflush(stdin);\
    printf("Press Enter...");\
    getchar();\
    fflush(stdin);\
}

#endif // STATUS_H
