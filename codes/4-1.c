#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define MAX 51

char arr[MAX][MAX];

int compare_q(char *a,char *exp){
    int len1=strlen(a);
    int len2=strlen(exp);

    char a1[51],exp1[51];
    for(int i=0;i<len1;i++){
        a1[i]=tolower(a[i]);
    }
    for(int i=0;i<len2;i++){
        exp1[i]=tolower(exp[i]);
    }
    int i=0,j=0;
    while(1){
        if(exp1[i]=='[') {
            i++;
            break;
        }
        if(exp[i]!=a1[i]) return 0;
        i++;
        j++;
    }
    int r1=len1-1;
    int r2=len2-1;
    while(1){
        if(exp1[r1]==']'){
            r1--;
            break;
        }
        if(exp1[r1]!=a1[r2]) return 0;
        r2--;
        r1--;
    }
    if(r2<=j){
        return 0;
    }
    for(int t=i;t<=r1;t++){
        if(a1[j]==exp1[t]){
            j++;
        }
    }
    if(j>r2) return 1;
    return 0;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",arr[i]);
    }
    char exp[MAX];
    scanf("%s",exp);
    int is_right[MAX];

    for(int i=0;i<n;i++){
        is_right[i]=compare_q(arr[i],exp);
    }
    
    for(int i=0;i<n;i++){
        if(is_right[i]){
            printf("%d",i+1);
            printf(" ");
            printf("%s",arr[i]);
            printf("\n");
        }
    }
    return 0;
}