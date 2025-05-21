#include<stdio.h>
#include<string.h>

#define MAX 2000

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        int card[MAX];
        int front=0,rear=0;
        for(int j=0;j<n;j++){
            int k;
            scanf("%d",&k);
            if(k==1){
                int op;
                scanf("%d",&op);
                card[rear++]=op;
            }else if(k==2){
                int c;
                scanf("%d",&c);
                if(c==0){
                    front++;
                }else{
                    rear--;
                }
            }
        }
        if(rear<=front){
            printf("NULL\n");
        }else{
            for(int m=front;m<rear;m++){
                if(m>front){
                    printf(" ");
                }
                printf("%d",card[m]);
            }
            printf("\n");
        }
    }
    return 0;
}