#include<stdio.h>
#include<string.h>

#define MAX 1000000

char s[MAX];

void find_max(char*s){
    int len=strlen(s);
    int hash[256]={0};
    for(int i=0;i<len;i++){
        int c=(unsigned char)s[i];
        hash[c]+=1;
    }
    int max=0;
    for(int i=1;i<256;i++){
        if(hash[i]>hash[max]){
            max=i;
        }
    }
    printf("%d",hash[max]);
}

int main(){
    while(scanf("%s",s)&&strcmp(s,".")!=0){
        find_max(s);
    }
    return 0;
}