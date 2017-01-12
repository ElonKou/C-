#define MAX_VERTAX_NUM  20
#include <stdio.h>
#include <stdlib.h>
#include <Status.h>

typedef struct ArcBox{
    //定义弧节点
    int tailvex,headvex;//尾头节点在表中的位置
    struct ArcBox *hlink,*tlink;//同弧头链表和同弧尾链表
    InfoType *info;//附加的弧信息
}ArcBox;

typedef struct{
    //定义顶点
    VertexType data;
    ArcBox *firstIn,*firstOut;
}VexNode;

typedef struct{
    VexNode xlist[MAX_VERTAX_NUM];//定义顶点列表
    int vexnum,arcnum;//定义数量
}OLGraph;

int LocateVex(OLGraph *G,VertexType u){
    //定位元素的位置
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
    //创建有向图
    printf("创建有向图，十字链表形式的：\n");
    printf("图的vexnum，arcnum\n");
    scanf("%d,%d",&G->vexnum,&G->arcnum);
    fflush(stdin);
    for(int i = 0;i<G->vexnum;i++){
        //开始输入顶点的数值并且初始化顶点列表内容
        printf("分别输入顶点的数值:\n");
        scanf("%c",&(G->xlist[i].data));
        G->xlist[i].firstIn = NULL;
        G->xlist[i].firstOut = NULL;
        fflush(stdin);
    }
    for(int i = 0;i<G->arcnum;i++){
        //开始输入每个弧的数值
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
