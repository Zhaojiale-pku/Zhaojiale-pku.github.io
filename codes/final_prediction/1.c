#include<stdio.h>
#include<string.h>

#define MAXN 20

int is_special(int num){
    char str[MAXN];
    sprintf(str,"%d",num);
    int len=strlen(str);

    for(int i=0;i<len;i++){
        if((((str[i]-'0')%2==1)&&(i%2==1))||
        (((str[i]-'0')%2==0)&&(i%2==0))){
            return 0;
        }
    }

    return 1;
}

int main(){
    int m;
    scanf("%d",&m);
    int special_nums[100];
    int special_count=0;

    for(int i=0;i<m;i++){
        int num;
        scanf("%d",&num);
        if(is_special(num)){
            special_nums[special_count++]=num;
        }
    }

    printf("%d\n",special_count);
    if(special_count==0){
        printf("***\n");
    }else{
        for(int i=0;i<special_count;i++){
            if(i>0){
                printf(" ");
            }
            printf("%d",special_nums[i]);
        }
    }

    return 0;
}