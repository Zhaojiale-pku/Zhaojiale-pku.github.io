#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int find_max(char arr[],int len){
    int max=0;
    for(int i=0;i<len;i++){
        if((unsigned char)arr[max]<(unsigned char)arr[i]){
            max=i;
        }
    }
    return max;
}

int main(){
    char s1[11];
    char s2[4];
    while(scanf("%s %3s",s1,s2)==2){
        int len=strlen(s1);
        int t=find_max(s1,len);
        for(int i=0;i<=t;i++){
            printf("%c",s1[i]);
        }
        printf("%s",s2);
        if(t<len-1){
            for(int i=t+1;i<len;i++){
                printf("%c",s1[i]);
            }
        }
        printf("\n");
    }
    return 0;
}