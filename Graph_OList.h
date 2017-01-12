#define MAX_VERTAX_NUM  20
#include <stdio.h>
#include <stdlib.h>
#include <Status.h>

typedef struct ArcBox{
    //���廡�ڵ�
    int tailvex,headvex;//βͷ�ڵ��ڱ��е�λ��
    struct ArcBox *hlink,*tlink;//ͬ��ͷ�����ͬ��β����
    InfoType *info;//���ӵĻ���Ϣ
}ArcBox;

typedef struct{
    //���嶥��
    VertexType data;
    ArcBox *firstIn,*firstOut;
}VexNode;

typedef struct{
    VexNode xlist[MAX_VERTAX_NUM];//���嶥���б�
    int vexnum,arcnum;//��������
}OLGraph;

int LocateVex(OLGraph *G,VertexType u){
    //��λԪ�ص�λ��
    int k = 0;
    for(int i=0;i<G->vexnum;i++){
        if(G->xlist[i].data == u){
            k = i;
            break;
        }else{
            k = 0;
        }
    }
    return k;
}

Status CreateOLG_DG(OLGraph *G){
    //��������ͼ
    printf("��������ͼ��ʮ��������ʽ�ģ�\n");
    printf("ͼ��vexnum��arcnum\n");
    scanf("%d,%d",&G->vexnum,&G->arcnum);
    fflush(stdin);
    for(int i = 0;i<G->vexnum;i++){
        //��ʼ���붥�����ֵ���ҳ�ʼ�������б�����
        printf("�ֱ����붥�����ֵ:\n");
        scanf("%c",&(G->xlist[i].data));
        G->xlist[i].firstIn = NULL;
        G->xlist[i].firstOut = NULL;
        fflush(stdin);
    }
    for(int i = 0;i<G->arcnum;i++){
        //��ʼ����ÿ��������ֵ
        VertexType a,b;
        scanf("%c,%c",&a,&b);
        fflush(stdin);
        int pos_a = LocateVex(G,a);
        int pos_b = LocateVex(G,b);
        //
        ArcBox *p = (ArcBox*)malloc(sizeof(ArcBox));
        //*p = {pos_a,pos_b,G->xlist[pos_b].firstIn,G->xlist[pos_a].firstOut,NULL};
        p->headvex = pos_a;
        p->tailvex = pos_b;
        p->hlink = G->xlist[pos_b].firstIn;
        p->tlink = G->xlist[pos_a].firstOut;
        p->info = NULL;
        G->xlist[pos_b].firstIn = G->xlist[pos_a].firstOut = p;
    }
    return OK;
}
