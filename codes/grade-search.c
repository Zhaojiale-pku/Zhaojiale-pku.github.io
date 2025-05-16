#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int val;
    int prio;
    int size;
    struct Node*left;
    struct Node*right;
}Node;

Node*create_node(int val){
    Node*new_node=(Node*)malloc(sizeof(Node));
    new_node->val=val;
    new_node->size=1;
    new_node->prio=rand();
    new_node->left=new_node->right=NULL;
    return new_node;
}

void update_size(Node*node){
    if(node==NULL)return;
    node->size=1;
    if(node->left)node->size+=node->left->size;
    if(node->right)node->size+=node->right->size;
}
