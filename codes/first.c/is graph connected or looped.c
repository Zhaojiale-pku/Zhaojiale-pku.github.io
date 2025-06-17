#include<stdio.h>
#include<memory.h>

#define MAXN 120

int m,n,G[MAXN][MAXN],visited[MAXN];
int total=0;

void dfsConnected(int v){
    visited[v]=1;
    total+=1;
    for(int u=0;u<n;u++){
        if(G[v][u]&&!visited[u]){
            dfsConnected(u);
        }
    }
}

int dfsLoop(int v,int x){
    visited[v]=1;
    for(int u=0;u<n;u++){
        if(G[v][u]){
            if(!visited[u]){
                if(dfsLoop(u,v))return 1;
            }else{
                if(u!=x)return 1;
            }
        }
    }
    return 0;
}

int main(){
    scanf("%d %d",&n,&m);
    memset(G,0,sizeof(G));
    memset(visited,0,sizeof(visited));

    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        G[a][b]=1;
        G[b][a]=1;
    }

    total=0;
    dfsConnected(0);
    if(total==n){
        printf("connected:yes\n");
    }else{
        printf("connected:no\n");
    }

    memset(visited,0,sizeof(visited));

    int loopFound=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(dfsLoop(i,-1)){
                loopFound=1;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(G[i][i]){
            loopFound=1;
            break;
        }
    }

    if(loopFound){
        printf("loop:yes\n");
    }else{
        printf("loop:no\n");
    }

    return 0;
}