#include<stdio.h>
#include<string.h>

#define MAX 1000

int get_value(const char*word){
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    if (strcmp(word, "ten") == 0) return 10;
    if (strcmp(word, "eleven") == 0) return 11;
    if (strcmp(word, "twelve") == 0) return 12;
    if (strcmp(word, "thirteen") == 0) return 13;
    if (strcmp(word, "fourteen") == 0) return 14;
    if (strcmp(word, "fifteen") == 0) return 15;
    if (strcmp(word, "sixteen") == 0) return 16;
    if (strcmp(word, "seventeen") == 0) return 17;
    if (strcmp(word, "eighteen") == 0) return 18;
    if (strcmp(word, "nineteen") == 0) return 19;
    if (strcmp(word, "twenty") == 0) return 20;
    if (strcmp(word, "thirty") == 0) return 30;
    if (strcmp(word, "forty") == 0) return 40;
    if (strcmp(word, "fifty") == 0) return 50;
    if (strcmp(word, "sixty") == 0) return 60;
    if (strcmp(word, "seventy") == 0) return 70;
    if (strcmp(word, "eighty") == 0) return 80;
    if (strcmp(word, "ninety") == 0) return 90;
    return -1;
}

int parse_number(char*line){
    int total=0,current=0,negative=0;
    char*token=strtok(line," ");
    while(token!=NULL){
        if(strcmp(token,"million")==0){
            total+=current*1000000;
            current=0;
        }else if(strcmp(token,"thousand")==0){
            total+=current*1000;
            current=0;
        }else if(strcmp(token,"hundred")==0){
            current*=100;
        }else if(strcmp(token,"negative")==0){
            negative=1;
        }
        else{
            int val=get_value(token);
            if(val>0){
                current+=val;
            }
        }
        token=strtok(NULL," ");
    }
    total+=current;
    return negative?-total:total;
}

int main(){
    char line[MAX];
    while(fgets(line,MAX,stdin)){
        if(line[0]=='\n')break;
        line[strcspn(line,"\n")]='\0';
        int result=parse_number(line);
        printf("%d\n",result);
    }
    return 0;
}