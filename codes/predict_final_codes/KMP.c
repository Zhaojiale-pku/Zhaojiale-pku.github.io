#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void buildNext(const char*pattern,int *next){
    int m=strlen(pattern);
    next[0]=0;
    int j=0;

    for(int i=1;i<m;i++){
        while(j>0&&pattern[i]!=pattern[j]){
            j=next[j-1];
        }

        if(pattern[i]==pattern[j]){
            j++;
        }

        next[i]=j;
    }
}

int kmpMatch(const char *text,const char *pattern){
    int n=strlen(text);
    int m=strlen(pattern);
    if(m==0)return 0;

    int*next=(int*)malloc(sizeof(int)*m);
    buildNext(pattern,next);

    int j=0;
    for(int i=0;i<n;i++){
        while(j>0&&text[i]!=pattern[j]){
            j=next[j-1];
        }

        if(text[i]==pattern[j]){
            j++;
        }

        if(j==m){
            free(next);
            return i-m+1;
        }
    }

    free(next);
    return -1;
}

int main(){
    const char *text="ababdadadd";
    const char *pattern="ababcdabd";

    int index=kmpMatch(text,pattern);
    if(index!=-1){
        printf("Pattern found at index:%d\n",index);
    }else{
        printf("Pattern not found.\n");
    }

    return 0;
}