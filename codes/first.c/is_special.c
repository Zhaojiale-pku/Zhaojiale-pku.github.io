#include<stdio.h>
#include<string.h>

int is_special(int num){
    char str[20];
    sprintf(str,"%d",num);
    int len=strlen(str);
    for(int i=0;i<len;i++){
        if(((str[i]-'0')%2==0&&(i%2==0))||
        ((str[i]-'0')%2==1&&(i%2==1))){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);
    int num_count=0;
    int special_nums[100];
    for(int i=0;i<n;i++){
        int num;
        scanf("%d",&num);
        if(is_special(num)){
            special_nums[num_count++]=num;
        }
    }
    printf("%d\n",num_count);
    if(num_count==0){
        printf("***\n");
    }else{
        for(int i=0;i<num_count;i++){
            if(i>0){
                printf(" ");
            }
            printf("%d",special_nums[i]);
        }
        printf("\n");
    }
    return 0;
}