#include<stdio.h>
#include<string.h>

#define MAX 101
#define MAXLEN 6

int main(){
    int m;
    scanf("%d",&m);

    while(m--){
        int card[MAX];
        int top=0;
        
        int n;
        int error=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            char s[MAXLEN];
            scanf("%s",s);
            if(strcmp(s,"push")==0){
                int t;
                scanf("%d",&t);
                card[top++]=t;
            }else{
                if(top==0){
                    error=1;
                }else if(top>0){
                    top--;
                }
            }
        }
        if(error==1){
            printf("error");
        }else{
            for(int i=0;i<top;i++){
                if(i>0)printf(" ");
                printf("%d",card[i]);
            }
        }
        printf("\n");
    }
    return 0;
}