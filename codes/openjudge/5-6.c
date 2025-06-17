#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NAME_LEN 31

typedef struct TreeNode{
    char name[MAX_NAME_LEN];
    int count;
    struct TreeNode *left,*right;
}TreeNode;

TreeNode* insert(TreeNode*root,char*name,int*total){
    if(root==NULL){
        TreeNode*node=(TreeNode*)malloc(sizeof(TreeNode));
        strcpy(node->name,name);
        node->count=1;
        node->left=node->right=NULL;
        (*total)++;
        return node;
    }

    int cmp=strcmp(name,root->name);
    if(cmp==0){
        root->count++;
        (*total)++;
    }else if(cmp<0){
        root->left=insert(root->left,name,total);
    }else if(cmp>0){
        root->right=insert(root->right,name,total);
    }
    return root;
}

void inorder(TreeNode*root,int total){
    if(root==NULL)return;
    inorder(root->left,total);
    double percentage=(double)root->count*100.0/total;
    printf("%s %.4lf\n",root->name,percentage);
    inorder(root->right,total);
}

void free_tree(TreeNode*root){
    if(root==NULL)return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main(){
    char buffer[MAX_NAME_LEN];
    int total=0;
    TreeNode*root=NULL;

    while(fgets(buffer,MAX_NAME_LEN,stdin)){
        buffer[strcspn(buffer,"\n")]='\0';
        if(strlen(buffer)>0){
            root=insert(root,buffer,&total);
        }
    }

    inorder(root,total);
    free_tree(root);
    return 0;
}