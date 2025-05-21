#include<stdio.h>
#include<string.h>

#define MAX 2000

int is_stack(int n){
    int top=0;
    int stack[MAX];
    int res=1;
    for(int i=0;i<n;i++){
        int k;int op;
        scanf("%d %d",&k,&op);
        if(k==1){
            stack[top++]=op;
        }else if(k==2){            
            if(top==0||stack[--top]!=op){
                res=0;
            }
        }
    }
    return res;
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        if(is_stack(n)){
            printf("Stack\n");
        }else{
            printf("Queue\n");
        }
    }
    return 0;
}