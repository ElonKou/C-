#include <stdio.h>

int main(){
    struct person{
        char name[20];
        int numner;
    }leader[3] = {{"Li",3},{"elon",5},{"kou",7}};
    printf("%s",leader[2].name);
    return 0;
}
