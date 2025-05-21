#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#include<time.h>

#define K 100
#define MAXLEN 81

void preprocess_expr(const char *input,char *output){
    int j=0;
    for(int i=0;input[i];i++){
        if(input[i]!=' '&&input[i]!='\t'){
            output[j++]=input[i];
        }
    }
    output[j]='\0';
}

void collect_vars(const char*expr,bool*vals_set){
    for(int i=0;expr[i];i++){
        unsigned char c=(unsigned char)expr[i];
        if(isalpha(c)){
            vals_set[c]=true;
        }
    }
}

long long parse_expression(const char *s,int *pos,const int vars[]);

long long parse_term(const char *s,int *pos,const int vars[]){
    if(s[*pos]=='('){
        (*pos)++;
        long long value=parse_expression(s,pos,vars);
        if(s[*pos]==')'){
            (*pos)++;
        }
        return value;
    }else if(isdigit(s[*pos])){
        long long num=s[*pos]-'0';
        (*pos)++;
        return num;
    }else if(isalpha(s[*pos])){
        char var=s[*pos];
        (*pos)++;
        return vars[(unsigned char)var];
    }
    return 0;
}

long long parse_expression(const char*s,int*pos,const int vars[]){
    long long value=parse_term(s,pos,vars);
    while(s[*pos]=='+'||s[*pos]=='-'||s[*pos]=='*'){
        char op=s[*pos];
        (*pos)++;
        long long term=parse_term(s,pos,vars);
        switch(op){
            case '+': value+=term;break;
            case '-': value-=term;break;
            case '*': value*=term;break;
        }
    }
    return value;
}

long long evaluate(const char *expr,const int vars[]){
    int pos=0;
    return parse_expression(expr,&pos,vars);
}

int main(){
    srand(time(NULL));
    int N;
    scanf("%d",&N);
    getchar();

    for(int t=0;t<N;t++){
        char expr1[MAXLEN],expr2[MAXLEN];
        fgets(expr1, MAXLEN, stdin);
        fgets(expr2, MAXLEN, stdin);

        expr1[strcspn(expr1, "\n")] = '\0';
        expr2[strcspn(expr2, "\n")] = '\0';

        char expr1_processed[MAXLEN], expr2_processed[MAXLEN];
        preprocess_expr(expr1, expr1_processed);
        preprocess_expr(expr2, expr2_processed);

        bool vars_set[256] = {false};
        collect_vars(expr1_processed, vars_set);
        collect_vars(expr2_processed, vars_set);

        bool equivalent = true;
        for (int i = 0; i < K; i++) {
            int vars[256] = {0};
            for (int c = 0; c < 256; c++) {
                if (vars_set[c]) {
                    vars[c] = rand() % 21 - 10;
                }
            }

            long long val1 = evaluate(expr1_processed, vars);
            long long val2 = evaluate(expr2_processed, vars);

            if (val1 != val2) {
                equivalent = false;
                break;
            }
        }

        printf("%s\n", equivalent ? "YES" : "NO");
    }

    return 0;
}
