#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100002
typedef struct Node{
    int pos;
    int time;
}Node;

int visited[MAX]={0};

int bfs(int n,int k){
    int rear=0,front=0;
    Node queue[2*MAX];
    queue[rear++]=(Node){n,0};
    visited[n]=1;
    while(front<rear){
        Node curr=queue[front++];
        if(curr.pos==k) return curr.time;
        int next_pos[3]={curr.pos-1,curr.pos+1,curr.pos*2};
        for(int i=0;i<3;i++){
            if(next_pos[i]>=0&&next_pos[i]<=MAX&&!visited[next_pos[i]]){
                visited[next_pos[i]]=1;//这一步赋值易漏
                queue[rear++]=(Node){next_pos[i],curr.time+1};
            }
        }
    }
    return -1;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int result=bfs(n,k);
    printf("%d",result);
    return 0;
}