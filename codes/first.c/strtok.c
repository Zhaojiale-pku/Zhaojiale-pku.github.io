#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE_LEN 1024
#define MAX_NUM_COUNT 1000

int main(){
    char line[MAX_LINE_LEN];
    int numbers[MAX_NUM_COUNT];
    int count=0;

    while(1){
        if(fgets(line,sizeof(line),stdin)==NULL){
            break;
        }

        char*token=strtok(line," ,\n\r\t");
        while(token!=NULL){
            numbers[count++]=atoi(token);
            token=strtok(NULL," ,\n\r\t");
        }
    }

    for(int i=0;i<count;i++){
        if(i>0)printf(" ");
        printf("%d",numbers[i]);
    }
    printf("\n");

    return 0;
}