#include<stdio.h>
#include<string.h>

#define MAXN 100
#define MAXLEN 4

typedef struct Queue{
    char card[MAXN][MAXLEN];
    int front,rear;
}Queue;

void q_init(Queue *q){
    q->front=q->rear=0;
}

int q_empty(const Queue *q){
    return q->front==q->rear;
}

void