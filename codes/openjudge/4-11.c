#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 400000


int next[MAX];

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

int out[MAX];

int main(){
    char line[MAX];
    while(scanf("%s",line)==1){
        int len=strlen(line);
        compute_next(line,len);
        int n=len-1;
        int t=0;
        
        int s=len;
        while(next[n]>-1){
            out[t++]=next[n]+1;
            n=next[n];
        }
        for(int i=t-1;i>=0;i--){
            printf("%d ",out[i]);
        }
        printf("%d\n",len);
    }
    return 0;
}