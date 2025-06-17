//计算一个无向图中所有连通分量的节点个数
#include<stdio.h>
#include<stdlib.h>

#define MAXN 1000

int adj[MAXN][MAXN];
int visited[MAXN];

int dfs(int u,int n){
    visited[u]=1;
    int count=1;
    for(int v=0;v<n;v++){
        if(adj[u][v]&&!visited[v]){
            count+=dfs(v,n);
        }
    }
    return count;
}

int main(){
    int n,m;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            adj[i][j]=0;
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("(%d,%d)",&u,&v);
        adj[u][v]=adj[v][u]=1;
    }

    for(int i=0;i<n;i++){
        visited[i]=0;
    }

    int components[MAXN];
    int cnt=0;

    for(int i=0;i<n;i++){
        if(!visited[i]){
            components[cnt++]=dfs(i,n);
        }
    }

    printf("[");
    for(int i=0;i<cnt;i++){
        printf("%d",components[i]);
        if(i<cnt-1)printf(",");
    }
    printf("]\n");

    return 0;
}