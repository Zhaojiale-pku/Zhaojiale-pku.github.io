#include<stdio.h>
#include<ctype.h>

void str_to_upper(char *str){
    for(int i=0;str[i];i++)
        str[i]=toupper(str[i]);
}

void str_to_lower(char *str){
    for(int i=0;str[i];i++)
        str[i]=tolower(str[i]);
}

int main(){
    char str1[]="Hello World!";
    char str2[]="C Language";

    str_to_upper(str1);
    str_to_lower(str2);

    printf("Upper:%s\n",str1);
    printf("Lower:%s\n",str2);

    return 0;
}
