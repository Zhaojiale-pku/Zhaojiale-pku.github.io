#include<stdio.h>
#include<string.h>

#define MAX 1000005

char s[MAX];
int next[MAX];

void compute_next(char*s,int len){
    int j=-1;
    next[0]=-1;
    for(int i=1;i<len;i++){
        while(j!=-1&&s[i]!=s[j+1]){
            j=next[j];
        }
        if(s[i]==s[j+1]){
            j++;
        }
        next[i]=j;
    }
}

int main(){
    while(scanf("%s",s)&&strcmp(s,".")!=0){
        int len=strlen(s);
        compute_next(s,len);
        int lps=next[len-1]+1;
        int period=len-lps;
        if(len%period==0){
            printf("%d\n",len/period);
        }else{
            printf("1\n");
        }
    }
    return 0;
}