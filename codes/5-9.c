#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int t;
    for(t=0;t<n;t++){
        int i,j;
        scanf("%d %d",&i,&j);
        int left=0,right=0;
        while(i>1||j>1){
            if(i<j){
                right+=j/i;
                j=j%i;
                if(j==0){
                    j=1;
                    right--;
                }
            }
            else if(i>j){
                left+=i/j;
                i=i%j;
                if(i==0){
                    i=1;
                    left--;
                }
            }
        }
        printf("Scenario #%d:\n",t+1);
        printf("%d %d\n\n",left,right);
    }
    return 0;
}