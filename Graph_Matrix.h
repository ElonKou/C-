#define INFINITY    INT_MAX
#define MAX_VERTEX_SIZE 20
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Status.h>
//ͼ�������ʾ
//��������,ͼ��

typedef enum {DG=1,DN,UDG,UDN} GraphKind;
typedef struct{
    VRType  adj;//�����Ƿ�����
    InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];

typedef struct{
    VertexType vexs[MAX_VERTEX_SIZE];
    GraphKind kind;
    AdjMatrix arcs;
    int vexnum,arcnum;
}MGraph;
//����һ��ͼ������


int LocateVex(MGraph *G,VertexType u){
    //��λ�����λ��
    int pos;
    for (int i = 0;i<G->vexnum;i++){
        if(G->vexs[i] == u){
            pos = i;
            break;
        }else{
            pos =  0;
        }
    }
    return pos;
}

Status CreateUDG_M(MGraph *G){
    //��������ͼ,���鷽ʽ
    printf("��ʼ��������ͼ\n");
    printf("������Ҫ������ͼ�Ķ�������,��������\n");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    for(int i = 0;i<G->vexnum;i++){
        //��ʼ����������
        printf("��ʼ�������ÿ���������Ϣ:\n");
        fflush(stdin);
        scanf("%c",&(G->vexs[i]));
    }
    for(int i=0;i<G->vexnum;i++){
        //��ʼ���ڽӾ���
        for(int j=0;j<G->vexnum;j++){
            //
            //G->arcs[i][j] = {INFINITY,NULL};
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    for(int i=0;i<G->arcnum;i++){
        //��ʼ���뻡��Ϣ
        printf("����һ��������Ϣ(��a ��b Ȩ��c):\n");
        VertexType a,b;
        VRType c;
        fflush(stdin);
        scanf("%c,%c,%d",&a,&b,&c);
        int pos_a = LocateVex(G,a);
        int pos_b = LocateVex(G,b);
        G->arcs[pos_a][pos_b].adj = G->arcs[pos_b][pos_a].adj = c;
    }
    return OK;
}

//�Ż�һ��ͼ���͵Ľṹ
Status CreateGraph(MGraph *G){
    //�����ĸ��������ֱ��Ƕ�UG,UDG,DN,UDN���й���
    printf("����ͼ����(DG:1,DN:2,UDG:3,UDN:4):\n");
    int tempKind;
    scanf("%d",&tempKind);
    G->kind =  (GraphKind)tempKind;
    switch(G->kind){
        case DG://����ͼ
            break;
        case DN://������
            break;
        case UDG://����ͼ
            return CreateUDG_M(G);
            break;
        case UDN://������
            break;
        default:
            return ERROR;
    }
    return OK;
}

MGraph CreateGraphRandom(MGraph *G,GraphKind kind,int dim){
    //�������һ�����Ӿ���,20ά
    srand((unsigned)time(NULL));
    G->kind = kind;
    G->vexnum = dim;
    G->arcnum = 0;
    int temp = 0;
    for(int i=0;i<dim;i++){
        G->vexs[i] = i+1;
        switch(G->kind){
            case UDG:
                for(int j = i;j<dim;j++){
                    temp = rand()%2;
                    G->arcnum +=(temp>0)?1:0;
                    G->arcs[i][j].adj = G->arcs[j][i].adj = temp;
                }
                break;
            case DG:
                for(int j = 0;j<dim;j++){
                    temp = rand()%2;
                    G->arcnum +=(temp>0)?1:0;
                    G->arcs[i][j].adj = temp;
                }
                break;
            default:
                break;
        }
    }
    return *G;
}

void PrintMG(MGraph *G){
    //��ӡĳ�����Ӿ������Ϣ
    printf("-------------------------\n");
    printf("ͼ������:");
    switch(G->kind){
        case DG:
            printf("DG(����ͼ)\n");
            break;
        case UDG:
            printf("UDG(����ͼ)\n");
            break;
        case DN:
            printf("DN(������)\n");
            break;
        case UDN:
            printf("UDN(������)\n");
            break;
        default:
            printf("error��û������\n");
            break;
    }
    printf("ͼ�ı���:%d\n",G->vexnum);
    printf("ͼ�Ļ�������:%d\n",G->arcnum);
    printf("ͼ�ı߷ֱ���:\n  ");
    for(int i = 0 ;i<G->vexnum;i++){
        printf("%c ",G->vexs[i]);
    }
    printf("\n");
    for(int i = 0 ;i<G->vexnum;i++){
        printf("%c ",G->vexs[i]);
        for(int j = 0;j<G->vexnum;j++){
            printf("%d ",G->arcs[i][j].adj);
        }
        printf("\n");
    }
}

void ClearMGraph(MGraph *G){
    //���ͼ����
    G->arcnum=0;
    G->vexnum=0;
    for(int i = 0 ;i<MAX_VERTEX_SIZE;i++){
        G->vexs[i] = 0;
    }
}


