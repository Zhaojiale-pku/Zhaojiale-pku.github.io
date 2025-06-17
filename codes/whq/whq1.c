#include<stdio.h>

int main(){
    double s;
    scanf("%lf",&s);
    unsigned long long *t=(unsigned long long*)&s;
    char str[18];
    sprintf(str,"%llx",*t);
    printf("0x");
    for(int i=0;i<8;i++){
        printf("%c",str[i]);
    }
    printf(" ");
    for(int i=8;i<16;i++){
        printf("%c",str[i]);
    }
    return 0;
}