#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LEN 2048
#define MAX_WORD_COUNT 1000
#define MAX_WORD_LEN 100

int main(){
    char line[MAX_LINE_LEN];
    char words[MAX_WORD_COUNT][MAX_WORD_LEN];
    int count=0;

    
    printf("请输入文本（按 Ctrl+D / Ctrl+Z+回车 结束）：\n");

    while(fgets(line,sizeof(line),stdin)!=NULL){
        char *token=strtok(line," ,.\n\r\t");
        while(token!=NULL){
            strncpy(words[count++],token,MAX_WORD_LEN);
            words[count-1][MAX_WORD_COUNT-1]='\0';
            token=strtok(NULL," ,.\n\t\r");
        }
    }

    for(int i=0;i<count;i++){
        printf("%s\n",words[i]);
    }

    return 0;
}