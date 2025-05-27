#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 65536

typedef struct TreeNode{
    int val;
    struct TreeNode*left,*right;
}TreeNode;

TreeNode*buildTree(int*inOrder,int*postOrder,int inStart,int postStart,int length){
    if(length<=0)return NULL;
    int rootval=postOrder[postStart+length-1];
    TreeNode*root=(TreeNode*)malloc(sizeof(TreeNode));
    root->val=rootval;
    root->left=root->right=NULL;
    int index=0;
    while(inOrder[inStart+index]!=rootval){
        index++;
    }
    root->left=buildTree(inOrder,postOrder,inStart,postStart,index);
    root->right=buildTree(inOrder,postOrder,inStart+index+1,postStart+index,length-index-1);
    return root;
}

int out_count=0;
int output[MAX];
void preTree(TreeNode*root){
    if(root==NULL)return;
    output[out_count++]=root->val;
    preTree(root->left);
    preTree(root->right);
}

void freeTree(TreeNode*root){
    if(root==NULL)return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int hash[65535]={0};
int inOrder[MAX]={0};
int postOrder[MAX]={0};
int input[2*MAX];


int main(){
    int count=0;
    int t;
    while(1){
        scanf("%d",&t);
        if(count>0&&t==inOrder[0]){
            postOrder[0]=t;
            break;
        }
        inOrder[count++]=t;
    }
    for(int i=1;i<count;i++){
        scanf("%d",&postOrder[i]);
    }
    TreeNode*root=buildTree(inOrder,postOrder,0,0,count);
    preTree(root);
    for(int i=0;i<out_count;i++){
        if(i>0){
            printf(" ");
        }
        printf("%d",output[i]);
    }
    freeTree(root);
    return 0;
}