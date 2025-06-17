#include<stdio.h>

#define MAX 80000

    int cow[MAX];
    int stack[MAX];
    int top=-1;

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",&cow[i]);
    }

    long long result=0;

    for(int i=n-1;i>=0;i--){
        while(top>=0&&cow[i]>cow[stack[top]]){
            top--;
        }
        stack[++top]=i;
        if(top==0){
            result+=n-i-1;
        }else{
            result+=stack[top-1]-i-1;
        }
    }
    printf("%lld",result);
    return 0;
}