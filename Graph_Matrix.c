#include <Graph_Matrix.h>
int main(){
    //��������
    /*MGraph P;
    MGraph G;
    MGraph mm = CreateGraphRandom(&P,UDG,4);
    MGraph mg = CreateGraphRandom(&G,DG,6);
    PrintMG(&mm);
    printf("\n\n");
    PrintMG(&mg);*/


    //���Դ���UDG
    MGraph GG;
    CreateGraph(&GG);
    PrintMG(&GG);
    return 0;
}
