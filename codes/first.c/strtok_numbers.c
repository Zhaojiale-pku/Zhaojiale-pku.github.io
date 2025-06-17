#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 1024

int main(){
    char line[MAX];
    int numbers[MAX];
    int count=0;

    while(1){
        if(fgets(line,MAX,stdin)==NULL){
            break;
        }

        char *token=strtok(line," ,\n\t\r");
        while(token!=NULL){
            numbers[count++]=atoi(token);
            token=strtok(NULL," ,\n\t\r");
        }
    }

    for(int i=0;i<count;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",numbers[i]);
    }
    printf("\n");
    return 0;
}