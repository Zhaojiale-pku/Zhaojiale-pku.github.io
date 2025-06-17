#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_LINE 2048
#define MAXN 200
#define MAX_WORD 200

int main(){
    char line[MAX_LINE];
    fgets(line,MAX_LINE,stdin);
    char words[MAXN][MAX_WORD];
    int word_count=0;

    char*token=strtok(line," ,.\n\t\r");
    while(token!=NULL&&word_count<MAXN){
        strcpy(words[word_count],token);
        words[word_count][MAX_WORD-1]='\0';
        word_count++;
        token=strtok(NULL," ,.\n\t\r");
    }

    printf("%d\n",word_count);

    for(int i=0;i<word_count;i++){
        if(i>0){
            printf(" ");
        }
        printf("%s",words[i]);
    }
    printf("\n");

    return 0;
}