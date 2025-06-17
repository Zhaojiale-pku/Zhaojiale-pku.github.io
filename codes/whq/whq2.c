#include<stdio.h>
#include<string.h>
#include<ctype.h>

int valid(char*s){
    if(s==NULL||s[0]=='\0'){
        return 0;
    }
    if(s[0]!='_'&&!isalpha(s[0])){
        return 0;
    }
    for(int i=1;s[i]!='\0';i++){
        if(!isalnum(s[i])&&s[i]!='_'){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++){
        char input[82];
        fgets(input,sizeof(input),stdin);
        input[strcspn(input,"\n")]='\0';
        printf("%d\n",valid(input));
    }
    return 0;
}