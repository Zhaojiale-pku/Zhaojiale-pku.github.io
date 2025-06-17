#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

char words[MAX_WORDS][MAX_LEN];
int word_count=0;

int cmp(const void *a,const void *b){
    return strcmp((const char*)a,(const char*)b);
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++){
        fgets(words[i],MAX_LEN,stdin);
        words[i][strcspn(words[i],"\n")]='\0';
    }
    word_count=n;

    qsort(words,word_count,MAX_LEN,cmp);

    for(int i=0;i<word_count;i++){
        printf("%s\n",words[i]);
    }
    
    return 0;
}