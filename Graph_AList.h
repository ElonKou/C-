#define MAX_VERTEX_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <Status.h>

//�����ڽӱ���ʽ������ͼ
typedef struct ArcNode{
    VRType adjvex;
    struct ArcNode *nextarc;
    InfoType *info;
}ArcNode,*Arcnode;

typedef struct{
    VertexType data;
    ArcNode *firstarc;
    ArcNode *lastarc;
}VNode,AdjList[MAX_VERTEX_SIZE];

typedef struct{
    AdjList vertices;
    int vexnum,arcnum;//����
    int kind;//ͼ�������־
}ALGraph;
//�ڽӱ�ʽ��ʾ���

int LocateVex(ALGraph *G,VertexType u){
    //�жϸ����u��ͼ�б��е�ʲôλ��
    int pos;
    for(int i=0;i<G->vexnum;i++){
        if(G->vertices[i].data==u){
            pos = i;
            break;
        }else{
            pos = 0;
        }
    }
    return pos;
}

Status CreateGAL_UDG(ALGraph *G){
    //��������ͼUDG
    fflush(stdin);
    printf("��������Ϣ");
    printf("�������������");
    scanf("%d,%d",&G->vexnum,&G->arcnum);

    for(int i = 0;i<G->vexnum;i++){
        //��ʼ����������
        printf("��ʼ�������ÿ���������Ϣ:\n");
        fflush(stdin);
        scanf("%c",&(G->vertices[i].data));
        //��ʼ���ڽӱ���ϢΪNULL
        G->vertices[i].firstarc = NULL;
        G->vertices[i].lastarc = NULL;
    }
    for(int i = 0;i<G->arcnum;i++){
        //�����ڽӱ���Ϣ����
        printf("�����ڽӱ���Ϣ(a,b,c):\n");
        VertexType a,b;
        VRType c;
        fflush(stdin);
        scanf("%c,%c,%d",&a,&b,&c);
        int pos_a = LocateVex(G,a);
        int pos_b = LocateVex(G,b);
        //����������ݽ��и�ֵ
        if(G->vertices[pos_a].firstarc == NULL){
            //��һ���ڵ��ǿյ�
            Arcnode node = (Arcnode)malloc(sizeof(ArcNode));
            G->vertices[pos_a].firstarc = node;
        }else{
            Arcnode node = (Arcnode)malloc(sizeof(ArcNode));
            Arcnode n = G->vertices[pos_a].firstarc;
            do{
                n = n->nextarc;
            }while(n == NULL);
            n = node;
        }
        //��B���и�ֵ
        if(G->vertices[pos_b].firstarc == NULL){
            //��һ���ڵ��ǿյ�
            Arcnode node = (Arcnode)malloc(sizeof(ArcNode));
            G->vertices[pos_b].firstarc = node;
        }else{
            Arcnode node = (Arcnode)malloc(sizeof(ArcNode));
            Arcnode n = G->vertices[pos_b].firstarc;
            do{
                n = n->nextarc;
            }while(n == NULL);
            n = node;
        }
    }
    return OK;
}

Status CreateGAL(ALGraph *G){
    //�����ڽӱ���ʽ��ͼ
    printf("����ͼ����(DG:1,DN:2,UDG:3,UDN:4):\n");
    scanf("%d",&G->kind);
    switch(G->kind){
        case 1:
            break;
        case 2:
            break;
        case 3:
            //��������ͼ
            return CreateGAL_UDG(G);
            break;
        case 4:
            break;
        default:
            break;
    }
    return OK;
}
