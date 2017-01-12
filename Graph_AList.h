#define MAX_VERTEX_SIZE 20
#include <stdio.h>
#include <stdlib.h>
#include <Status.h>

//创建邻接表形式存贮的图
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
    int vexnum,arcnum;//数量
    int kind;//图的种类标志
}ALGraph;
//邻接表方式表示完成

int LocateVex(ALGraph *G,VertexType u){
    //判断给如的u在图列表中的什么位置
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
    //创建无向图UDG
    fflush(stdin);
    printf("请输入信息");
    printf("输入边数，弧数");
    scanf("%d,%d",&G->vexnum,&G->arcnum);

    for(int i = 0;i<G->vexnum;i++){
        //初始化顶点向量
        printf("开始逐次输入每个顶点的信息:\n");
        fflush(stdin);
        scanf("%c",&(G->vertices[i].data));
        //初始化邻接表信息为NULL
        G->vertices[i].firstarc = NULL;
        G->vertices[i].lastarc = NULL;
    }
    for(int i = 0;i<G->arcnum;i++){
        //输入邻接表弧信息内容
        printf("输入邻接表信息(a,b,c):\n");
        VertexType a,b;
        VRType c;
        fflush(stdin);
        scanf("%c,%c,%d",&a,&b,&c);
        int pos_a = LocateVex(G,a);
        int pos_b = LocateVex(G,b);
        //对输入的数据进行赋值
        if(G->vertices[pos_a].firstarc == NULL){
            //第一个节点是空的
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
        //对B进行赋值
        if(G->vertices[pos_b].firstarc == NULL){
            //第一个节点是空的
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
    //创建邻接表形式的图
    printf("输入图类型(DG:1,DN:2,UDG:3,UDN:4):\n");
    scanf("%d",&G->kind);
    switch(G->kind){
        case 1:
            break;
        case 2:
            break;
        case 3:
            //创建无向图
            return CreateGAL_UDG(G);
            break;
        case 4:
            break;
        default:
            break;
    }
    return OK;
}
