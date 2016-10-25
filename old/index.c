#include <stdio.h>
#include <string.h>

int main(){
    printf("C:\\Cmd/>");
    char comall[1024]= {0};
    while(1){
        scanf("%s",comall);
        if(!strcmp(comall,"dododo")){
            printf("C:\\Cmd/>");


            printf("do something of do\n");
            printf("C:\\Cmd/>");
        }else if(!strcmp(comall,"qu")){
            printf("C:\\Cmd/>");


            printf("do qu something\n");
            printf("C:\\Cmd/>");
        }else if(!strcmp(comall,"exit")){
            printf("C:\\Cmd/>");
            printf("exit now!");
            break;
        }else{
            printf("C:\\Cmd/>");
        }
    }
    return 0;
}

