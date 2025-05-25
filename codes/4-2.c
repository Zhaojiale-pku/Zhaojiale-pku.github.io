#include<stdio.h>

int main(){
    int c,next;
    enum{NORMAL,IN_COMMENT,IN_STRING,IN_CHAR}state=NORMAL;

    while((c=getchar())!=EOF){
        switch(state){
            case NORMAL:
                if(c=='/'){
                    next=getchar();
                    if(next=='*'){
                        state=IN_COMMENT;
                    }else{
                        putchar(c);
                        putchar(next);
                    }
                }else if(c=='"'){
                    putchar(c);
                    state=IN_STRING;
                }else if(c=='\''){
                    putchar(c);
                    state=IN_CHAR;
                }else{
                    putchar(c);
                }
                break;

            case IN_COMMENT:
                if(c=='*'){
                    next=getchar();
                    if(next=='/'){
                        state=NORMAL;
                    }else{
                        ungetc(next,stdin);
                    }
                }
                break;

            case IN_STRING:
                putchar(c);
                if(c=='\\'){
                    next=getchar();
                    putchar(next);
                }else if(c=='"'){
                    state=NORMAL;
                }
                break;

            case IN_CHAR:
                putchar(c);
                if(c=='\\'){
                    next=getchar();
                    putchar(next);
                }else if(c=='\''){
                    state=NORMAL;
                }
                break;
        }
    }
    return 0;
}