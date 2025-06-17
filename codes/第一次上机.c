#include<stdio.h>
#define MAX_N 50
#define MAX_K 1000

int graph[MAX_N+1][MAX_N+1];
int colors[MAX_N+1];
int n,k;

// 函数f:判断顶点v是否可以用颜色c染色
int f(int v,int c){
    for(int i=1;i<=n;i++){
        if(graph[v][i]&&colors[i]==c){
            return 0;
        }
    }
    return 1;
}

// 函数g：使用回溯算法判断图是否可以m染色
int g(int v,int m){
    if(v==n+1){
        return 1;
    }
    for(int c=1;c<=m;c++){
        if(f(v,c)){
            colors[v]=c;
            if(g(v+1,m)){
                return 1;
            }else{
                colors[v]=0;
            }
        }
    }
    return 0;
}

// 函数h：找到最小的m使得图可以m染色
int h(){
    for(int m=1;m<=n;m++){
        for(int i=1;i<=n;i++){
            colors[i]=0;
        }
        if(g(1,m)){
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
    int min=h();
    printf("%d",min);
    return 0;
}