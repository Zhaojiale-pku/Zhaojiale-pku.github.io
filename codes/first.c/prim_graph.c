#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define MAXN 100

int n,m;
int graph[MAXN][MAXN];

void prim(){
    int key[MAXN];
    bool inMST[MAXN];
    int parent[MAXN];

    for(int i=0;i<n;i++){
        key[i]=INT_MAX;
        inMST[i]=false;
        parent[i]=-1;
    }

    key[0]=0;

    for(int count=0;count<n-1;count++){
        int u=-1,minKey=INT_MAX;

        for(int v=0;v<n;v++){
            if(!inMST[v]&&key[v]<minKey){
                minKey=key[v];
                u=v;
            }
        }

        inMST[u]=true;

        for(int v=0;v<n;v++){
            if(graph[u][v]&&graph[u][v]<key[v]){
                key[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }

    for(int i=1;i<n;i++){
        printf("(%d,%d)\n",i,parent[i]);
    }
}

int main(){
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            graph[i][j]=0;

    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w;
    }

    prim();

    return 0;
}