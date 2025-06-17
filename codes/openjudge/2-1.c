#include<stdio.h>
#include<stdlib.h>

typedef struct Term{
    int coef;
    int exp;
    struct Term*next;
}Term;

void insert_term(Term**head,int coef,int exp){
    if(coef==0)return;

    Term*prev=NULL;
    Term*curr=*head;

    while(curr&&curr->exp>exp){
        prev=curr;
        curr=curr->next;
    }

    if(curr&&curr->exp==exp){
        curr->coef+=coef;
        if(curr->coef==0){
            if(prev){
                prev->next=curr->next;
            }else{
                *head=curr->next;
            }
            free(curr);
        }
    }else{
        Term*new_term=(Term*)malloc(sizeof(Term));
        new_term->coef=coef;
        new_term->exp=exp;
        new_term->next=curr;
        if(prev){
            prev->next=new_term;
        }else{
            *head=new_term;
        }
    }
}

void print_poly(Term*head){
    while(head){
        printf("[ %d %d ]",head->coef,head->exp);
        if(head->next){
            printf(" ");
        }
        head=head->next;
    }
    printf("\n");
}

void free_list(Term*head){
    Term*curr=head;
    while(curr){
        Term*tmp=curr;
        curr=curr->next;
        free(tmp);
    }
}

int main(){
    int n;
    scanf("%d",&n);

    while(n--){
        Term*result=NULL;
        int x,y;

        for(int i=0;i<2;++i){
            while(1){
                scanf("%d %d",&x,&y);
                if(y<0) break;
                insert_term(&result,x,y);
            }
        }
        print_poly(result);
        free_list(result);
    }
    return 0;
}