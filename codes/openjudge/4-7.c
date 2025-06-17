#include<stdio.h>
#include<string.h>

#define MAX 205

void decrypt(char*s){
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            s[i]=(s[i]-'A'-5+26)%26+'A';
        }
    }
    printf("%s\n",s);
}

int main(){
    char command[20];
    char s[MAX];
    while(scanf("%s",command)&&strcmp(command,"ENDOFINPUT")!=0){
        getchar();
        fgets(s,MAX,stdin);
        scanf("%s",command);
        s[strcspn(s,"\n")]='\0';
        decrypt(s);
    }
    return 0;
}