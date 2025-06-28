#include<stdio.h>
#define MAX_N 51

int graph[MAX_N][MAX_N];
int colors[MAX_N];
int n,k;

int is_safe(int v,int c){
    for(int i=1;i<=n;i++){
        if(graph[v][i]&&colors[i]==c){
            return 0;
        }
    }
    return 1;
}

int graph_coloring(int v,int m){
    if(v==n+1){
        return 1;
    }
    for(int i=1;i<=m;i++){
        if(is_safe(v,i)){
            colors[v]=i;
            if(graph_coloring(v+1,m)){
                return 1;
            }else{
                colors[i]=0;
            }
        }
    }
    return 0;
}

int h(){
    for(int m=1;m<=n;m++){
        for(int i=1;i<=n;i++){
            colors[i]=0;
        }
        if(graph_coloring(1,m)){
            return m;
        }
    }
    return n;
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        graph[a][b]=1;
        graph[b][a]=1;
    }
    int result=h();
    printf("%d",result);
    return 0;
}