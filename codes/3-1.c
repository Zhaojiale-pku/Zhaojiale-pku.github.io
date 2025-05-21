#include<stdio.h>
#include<string.h>

#define MAXN 101
#define MAXLEN 4
typedef struct Queue{
    char card[MAXN][MAXLEN];
    int front,rear;
}Queue;

void q_init(Queue*q){
    q->rear=q->front=0;
}

int q_empty(Queue*q){
    return q->rear==q->front;
}

void q_push(Queue*q,char*s){
    strcpy(q->card[q->rear++],s);
}

void q_pop(Queue*q,char*s){
    strcpy(s,q->card[q->front++]);
}

void print_rank_queue(Queue*q,int rank){
    printf("Queue%d:",rank);
    for(int i=q->front;i<q->rear;i++){
        if(i>q->front){
            printf(" ");
        }
        printf("%s",q->card[i]);//这里不能写成q->card!!!!
    }
    printf("\n");
}

void print_suit_queue(Queue*q,char suit){
    printf("Queue%c:",suit);
    for(int i=q->front;i<q->rear;i++){
        if(i>q->front){
            printf(" ");
        }
        printf("%s",q->card[i]);
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    Queue rank_q[10];
    for(int i=1;i<=9;i++){
        q_init(&rank_q[i]);
    }

    for(int i=0;i<n;i++){
        char card[MAXLEN];
        scanf("%s",card);
        int rank=card[1]-'0';
        q_push(&rank_q[rank],card);
    }

    for(int i=1;i<=9;i++){
        print_rank_queue(&rank_q[i],i);
    }

    char seq[MAXN][MAXLEN];
    int seq_len=0;
    for(int i=1;i<=9;i++){
        while(!q_empty(&rank_q[i])){
            q_pop(&rank_q[i],seq[seq_len++]);
        }
    }

    for(int i=1;i<=4;i++){
        q_init(&rank_q[i]);
    }

    for(int i=0;i<seq_len;i++){
        int suit=seq[i][0]-'A'+1;
        q_push(&rank_q[suit],seq[i]);
    }

    print_suit_queue(&rank_q[1],'A');
    print_suit_queue(&rank_q[2],'B');
    print_suit_queue(&rank_q[3],'C');
    print_suit_queue(&rank_q[4],'D');

    char final[MAXN][MAXLEN];
    int final_len=0;
    for(int i=1;i<=4;i++){
        while(!q_empty(&rank_q[i])){
            q_pop(&rank_q[i],final[final_len++]);
        }
    }

    for(int i=0;i<final_len;i++){
        if(i>0){
            printf(" ");
        }
        printf("%s",final[i]);
    }

    return 0;
}