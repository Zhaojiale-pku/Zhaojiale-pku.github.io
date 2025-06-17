#include<stdio.h>
#include<string.h>

#define MAX 10001

char arr[MAX];
int stack[MAX];
int top=-1;

int main(){
    scanf("%s",arr);
    int len=strlen(arr);
    for(int i=0;i<len;i++){
        if(top>=0){
            if(arr[stack[top]]-'['==0&&arr[i]-']'==0){
                top--;
                continue;
            }
            else if(arr[stack[top]]-'('==0&&arr[i]-')'==0){
                top--;
                continue;
            }
            else if(arr[stack[top]]-'{'==0&&arr[i]-'}'==0){
                top--;
                continue;
            }
        }
        stack[++top]=i;
    }
    if(top==-1){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}