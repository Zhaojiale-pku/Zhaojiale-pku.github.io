#include<stdio.h>

#define MAX 1000000

int card[MAX];
int min_q[MAX],min_head=0,min_tail=-1;
int max_q[MAX],max_head=0,max_tail=-1;
int min_res[MAX];
int max_res[MAX];

int main(){
    int n;
    scanf("%d",&n);
    int k;
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        scanf("%d",&card[i]);
    }
    for(int i=0;i<n;i++){
        //min
        while(min_head<=min_tail&&card[min_q[min_tail]]>card[i])
            min_tail--;
        min_q[++min_tail]=i;
        if(min_q[min_head]<=i-k) min_head++;
        min_res[i]=card[min_q[min_head]];
        //max
        while(max_head<=max_tail&&card[max_q[max_tail]]<card[i])
            max_tail--;
        max_q[++max_tail]=i;
        if(max_q[max_head]<=i-k) max_head++;
        max_res[i]=card[max_q[max_head]];

    }
    for(int i=k-1;i<n;i++){
        if(i>k-1)printf(" ");
        printf("%d",min_res[i]);
    }
    printf("\n");
    for(int i=k-1;i<n;i++){
        if(i>k-1)printf(" ");
        printf("%d",max_res[i]);
    }
    return 0;
}
