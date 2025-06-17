#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 27

typedef struct TreeNode{
    char val;
    struct TreeNode*left,*right;
}TreeNode;

TreeNode*buildTree(char*preOrder,char*inOrder,int preStart,int inStart,int length){
    if(length<=0)return NULL;
    TreeNode*root=(TreeNode*)malloc(sizeof(TreeNode));
    char rootval=preOrder[preStart];
    root->val=rootval;
    root->left=root->right=NULL;
    int index=0;
    while(inOrder[inStart+index]!=rootval){
        index++;
    }
    root->left=buildTree(preOrder,inOrder,preStart+1,inStart,index);
    root->right=buildTree(preOrder,inOrder,preStart+index+1,inStart+index+1,length-index-1);
    return root;
}

void postTree(TreeNode*root){
    if(root==NULL)return;
    postTree(root->left);
    postTree(root->right);
    putchar(root->val);
}

void freeTree(TreeNode*root){
    if(root==NULL)return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    char preOrder[MAX];
    char inOrder[MAX];
    while(scanf("%s %s",preOrder,inOrder)==2){
        int len=strlen(preOrder);
        TreeNode*root=buildTree(preOrder,inOrder,0,0,len);
        postTree(root);
        freeTree(root);
        putchar('\n');
    }
    return 0;
}
