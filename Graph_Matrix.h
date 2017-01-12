#define INFINITY    INT_MAX
#define MAX_VERTEX_SIZE 20
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Status.h>
//图的数组表示
//定义有无,图网

typedef enum {DG=1,DN,UDG,UDN} GraphKind;
typedef struct{
    VRType  adj;//定义是否连接
    InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_SIZE][MAX_VERTEX_SIZE];

typedef struct{
    VertexType vexs[MAX_VERTEX_SIZE];
    GraphKind kind;
    AdjMatrix arcs;
    int vexnum,arcnum;
}MGraph;
//申明一个图的类型


int LocateVex(MGraph *G,VertexType u){
    //定位顶点的位置
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
    //创建无向图,数组方式
    printf("开始输入无向图\n");
    printf("输入需要创建的图的顶点数量,弧的数量\n");
    scanf("%d %d",&(G->vexnum),&(G->arcnum));
    for(int i = 0;i<G->vexnum;i++){
        //初始化顶点向量
        printf("开始逐次输入每个顶点的信息:\n");
        fflush(stdin);
        scanf("%c",&(G->vexs[i]));
    }
    for(int i=0;i<G->vexnum;i++){
        //初始化邻接矩阵
        for(int j=0;j<G->vexnum;j++){
            //
            //G->arcs[i][j] = {INFINITY,NULL};
            G->arcs[i][j].adj = 0;
            G->arcs[i][j].info = NULL;
        }
    }
    for(int i=0;i<G->arcnum;i++){
        //开始输入弧信息
        printf("输入一条弧的信息(边a 边b 权重c):\n");
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

//放回一个图类型的结构
Status CreateGraph(MGraph *G){
    //包含四个方法，分别是对UG,UDG,DN,UDN进行构造
    printf("输入图类型(DG:1,DN:2,UDG:3,UDN:4):\n");
    int tempKind;
    scanf("%d",&tempKind);
    G->kind =  (GraphKind)tempKind;
    switch(G->kind){
        case DG://有向图
            break;
        case DN://有向网
            break;
        case UDG://无向图
            return CreateUDG_M(G);
            break;
        case UDN://无向网
            break;
        default:
            return ERROR;
    }
    return OK;
}

MGraph CreateGraphRandom(MGraph *G,GraphKind kind,int dim){
    //随机生成一个链接矩阵,20维
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
    //打印某个链接矩阵的信息
    printf("-------------------------\n");
    printf("图的类型:");
    switch(G->kind){
        case DG:
            printf("DG(有向图)\n");
            break;
        case UDG:
            printf("UDG(无向图)\n");
            break;
        case DN:
            printf("DN(有向网)\n");
            break;
        case UDN:
            printf("UDN(无向网)\n");
            break;
        default:
            printf("error：没有类型\n");
            break;
    }
    printf("图的边数:%d\n",G->vexnum);
    printf("图的弧的数量:%d\n",G->arcnum);
    printf("图的边分别是:\n  ");
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
    //清空图方法
    G->arcnum=0;
    G->vexnum=0;
    for(int i = 0 ;i<MAX_VERTEX_SIZE;i++){
        G->vexs[i] = 0;
    }
}


