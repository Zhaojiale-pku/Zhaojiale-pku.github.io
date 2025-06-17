#include<stdio.h>
#include<string.h>

#define MAX 200

void transfer(char str[],int arr[],int*len){
    *len=strlen(str);
    for(int i=0;i<*len;i++){
        arr[i]=str[*len-1-i]-'0';
    }
}

int main(){
    char s1[MAX+1];
    char s2[MAX+1];
    scanf("%s",s1);
    scanf("%s",s2);
    int len1;
    int len2;
    int a1[MAX+1];
    int a2[MAX+1];
    transfer(s1,a1,&len1);
    transfer(s2,a2,&len2);

    int result[2*MAX+1]={0};
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            result[i+j]+=a1[i]*a2[j];
            if(result[i+j]>=10){
                result[i+j+1]+=result[i+j]/10;
                result[i+j]=result[i+j]%10;
            }
        }
    }
    int highest=len1+len2-1;
    while(highest>0&&result[highest]==0){
        highest--;
    }
    
    for(int i=0;i<=highest;i++){
        printf("%d",result[highest-i]);
    }
    return 0;
}

