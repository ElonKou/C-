#include <stdio.h>
#include <stdlib.h>

int main(){
    //���ö�����͵��������
    enum week{MON=1,TUES,WEDN,THIR,FIR,SAT,SUN};
    enum week day;
    printf("�������ڼ�?\n");
    scanf("%d",&day);
    switch(day){
        case MON:
            printf("MON:%d\n",day);
            break;
        case TUES:
            printf("TUES:%d\n",day);
            break;
        case WEDN:
            printf("WEDN:%d\n",day);
            break;
        case THIR:
            printf("THIR:%d\n",day);
            break;
        case FIR:
            printf("FIR:%d\n",day);
            break;
        case SAT:
            printf("SAT:%d\n",day);
            break;
        case SUN:
            printf("SUN:%d\n",day);
            break;
    }
}
