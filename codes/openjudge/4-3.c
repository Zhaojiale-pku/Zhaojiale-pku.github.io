#include<stdio.h>
#include<string.h>

#define MAX 1000000

char s[MAX],t[MAX];

int compare(char*s,char*t){
    int len_s=strlen(s);
    int len_t=strlen(t);
    int i=0,j=0;
    while(i<len_s&&j<len_t){
        if(s[i]==t[j]){
            i++;

            j++;

        }else{
            j++;
        }
    }
    if(i==len_s){
        return 1;
    }
    return 0;
}

int main(){
    while(1){
        if(scanf("%s",s)!=1){
            break;
        }
        scanf("%s",t);
        if(compare(s,t)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}