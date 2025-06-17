#include<stdio.h>
#include<string.h>

#define MAX 1001

char s[MAX];

void find_max(char*s){
    int hash[26]={0};
    int len=strlen(s);
    for(int i=0;i<len;i++){
        hash[s[i]-'a']+=1;
    }
    int max=0;
    for(int i=1;i<=25;i++){
        if(hash[i]>hash[max]){
            max=i;
        }
    }
    printf("%c %d\n",max+'a',hash[max]);
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        find_max(s);
    }
    return 0;
}