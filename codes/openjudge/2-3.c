#include<stdio.h>
#include<stdlib.h>

#define MAXN 100005

int arr[MAXN];
int m,n;

int main(){
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        char op;
        scanf(" %c",&op);
        int t;
        scanf("%d",&t);
        if(op=='Q'){
            int count=0;
            for(int j=0;j<m;j++){
                count+=((arr[j]>>t)&1);
            }
            printf("%d\n",count);
        }
        else if(op=='C'){
            for(int j=0;j<m;j++){
                arr[j]=(arr[j]+t)%65536;
            }
        }
    }
    return 0;
}