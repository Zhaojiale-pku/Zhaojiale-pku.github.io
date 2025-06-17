#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 101

char s1[MAX];
char t1[MAX];

int s2[26]={0};
int t2[26]={0};

int compare(const void*a,const void*b){
    return (*(int*)a-*(int*)b);
}

void char_to_int(char*s1,int*s2){
    int len=strlen(s1);
    for(int i=0;i<len;i++){
        s2[s1[i]-'A']+=1;
    }
    qsort(s2,26,sizeof(int),compare);
}

int main(){
    scanf("%s %s",s1,t1);
    if(strlen(s1)!=strlen(t1)){
        printf("No\n");
        return 0;
    }
    char_to_int(s1,s2);
    char_to_int(t1,t2);
    for(int i=0;i<26;i++){
        if(s2[i]!=t2[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}