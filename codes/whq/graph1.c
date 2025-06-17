#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct EdgeNode{
    int endvex;
    int weight;
    struct EdgeNode*nextedge;
}EdgeNode,*PEdgeNode,*EdgeList;

typedef struct{
    int vertex;
    EdgeList edgelist;
}VexNode;

typedef struct{
    int n;
    VexNode* vexs;
}GraphList;

void findInDegree(GraphList*g,int*indegree){
    int i;
    PEdgeNode p;
    for(i=0;i<g->n;i++)
        indegree[i]=0;

    for(i=0;i<g->n;i++){
        p=g->vexs[i].edgelist;
        while(p){
            indegree[p->endvex]++;
            p=p->nextedge;
        }
    }
}

int topoSort(GraphList* paov,int* ptopo){
    EdgeList p;
    int i,j,k;
    int nodeno=0;
    int top=-1;
    int* indegree=(int*)malloc(sizeof(int)*paov->n);
    findInDegree(paov,indegree);

    for(i=0;i<paov->n;i++){
        if(indegree[i]==0){
            indegree[i]=top;
            top=i;
        }
    }

    while(top!=-1){
        j=top;
        top=indegree[top];

        ptopo[nodeno++]=j;

        p=paov->vexs[j].edgelist;
        while(p){
            k=p->endvex;
            indegree[k]--;

            if(indegree[k]==0){
                indegree[k]=top;
                top=k;
            }

            p=p->nextedge;
        }
    }

    free(indegree);

    if(nodeno<paov->n){
        printf("The AOV network has a cycle\n");
        return 0;
    }

    return 1;
}

// 构建一个简单图的例子（手动添加边）
GraphList* createSampleGraph() {
    int n = 6;
    GraphList* g = (GraphList*)malloc(sizeof(GraphList));
    g->n = n;
    g->vexs = (VexNode*)malloc(sizeof(VexNode) * n);

    for (int i = 0; i < n; i++) {
        g->vexs[i].vertex = i;
        g->vexs[i].edgelist = NULL;
    }

    // 添加边 (0->2), (0->3), (1->3), (1->4), (2->5), (3->5), (4->5)
    int edges[][2] = {{0,2},{0,3},{1,3},{1,4},{2,5},{3,5},{4,5}};
    int edge_count = sizeof(edges) / sizeof(edges[0]);

    for (int i = 0; i < edge_count; i++) {
        int from = edges[i][0];
        int to = edges[i][1];
        PEdgeNode newedge = (PEdgeNode)malloc(sizeof(EdgeNode));
        newedge->endvex = to;
        newedge->weight = 1; // 可省略
        newedge->nextedge = g->vexs[from].edgelist;
        g->vexs[from].edgelist = newedge;
    }

    return g;
}

// 销毁图，释放内存
void destroyGraph(GraphList* g) {
    for (int i = 0; i < g->n; i++) {
        PEdgeNode p = g->vexs[i].edgelist;
        while (p) {
            PEdgeNode temp = p;
            p = p->nextedge;
            free(temp);
        }
    }
    free(g->vexs);
    free(g);
}

// 主函数
int main() {
    GraphList* paov = createSampleGraph(); // 构建样例图

    if (paov->n == 0) return 0;

    int* ptopo = (int*)malloc(sizeof(int) * paov->n);

    if (topoSort(paov, ptopo)) {
        printf("拓扑排序结果：");
        for (int i = 0; i < paov->n; i++)
            printf("%d ", ptopo[i]);
        printf("\n");
    }

    free(ptopo);
    destroyGraph(paov);

    return 0;
}