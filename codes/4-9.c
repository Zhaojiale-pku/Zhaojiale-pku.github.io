#include<stdio.h>
#include<string.h>

#define MAX 1000001

int next[MAX];
char S[MAX];

void compute_next(char*line,int len){
    next[0]=-1;
    int j=-1;
    for(int i=1;i<len;i++){
        while(j!=-1&&line[i]!=line[j+1]){
            j=next[j];
        }
        if(line[i]==line[j+1]){
            j++;
        }
        next[i]=j;
    }
}

int main(){
    int n;
    int k=1;
    while(scanf("%d",&n)==1&&n!=0){
        scanf("%s",S);
        int len=strlen(S);
        compute_next(S,len);
        printf("Test case #%d\n",k++);
        for(int i=1;i<len;i++){
            int lps=next[i]+1;
            int period=i+1-lps;
            if((i+1)%period==0&&lps>0){
                int vsl=(i+1)/period;
                printf("%d %d\n",i+1,vsl);
            }
        }
        printf("\n");
    }
}