#include<stdio.h>
#include<string.h>

int main(){
    char str[]="Hello,world!";
    char *substr=strstr(str,"world");

    if(substr)
        printf("Found at:%ld\n",substr-str);
    else    
        printf("Not found\n");

    return 0;
}