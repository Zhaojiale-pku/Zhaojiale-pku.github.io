#include<stdio.h>

int count(int m,int n){
    if(m==0)return 1;
    if(n==0)return 0;
    if(m<0)return 0;
    if(n<0)return 0;
    if(m<n)return count(m,m);
    return count(m,n-1)+count(m-n,n);
}

int main(){
    int t;
    scanf("%d",&t);
    int m,n;
    for(int i=0;i<t;i++){
        scanf("%d %d",&m,&n);
        printf("%d\n",count(m,n));
    }
    return 0;
}