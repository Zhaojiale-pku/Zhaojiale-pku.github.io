#include<stdio.h>
#include<stdlib.h>

#define MAX 1000001

int hash[MAX]={0};

int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    int *q=(int*)malloc(M*sizeof(int));
    int front=0,rear=0;
    int ans=0;
    int count=0;

    for(int i=0;i<N;i++){
        int op;
        scanf("%d",&op);
        if(hash[op]==1){
            continue;
        }
        if(count<M){
            q[rear]=op;
            count++;
            hash[op]=1;
            rear=(rear+1)%M;
        }else{
            int out=q[front];
            hash[out]=0;
            front=(front+1)%M;//满了之后先出后进，烧杯

            q[rear]=op;
            hash[op]=1;
            rear=(rear+1)%M;
        }
        ans++;
    }
    free(q);
    printf("%d",ans);
    return 0;
}