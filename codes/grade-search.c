#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int val;
    int size;
    int prio;
    struct Node*right;
    struct Node*left;
}Node;

Node*create_node(int val){
    Node*root=(Node*)malloc(sizeof(Node));
    root->val=val;
    root->size=1;
    root->prio=rand();
    root->left=root->right=NULL;
    return root;
}

void update_size(Node*root){
    if(root==NULL)return;
    root->size=1;
    if(root->left)root->size+=root->left->size;
    if(root->right)root->size+=root->right->size;
}

Node*rotate_right(Node*x){
    Node*y=x->left;
    Node*T2=y->right;
    y->right=x;
    x->left=T2;
    update_size(x);
    update_size(y);
    return y;
}

Node*rotate_left(Node*y){
    Node*x=y->right;
    Node*T2=x->left;
    x->left=y;
    y->right=T2;
    update_size(y);
    update_size(x);
    return x;
}

Node*insert_node(Node*root,int x){
    if(root==NULL)return create_node(x);
    if(root->val>=x){
        root->left=insert_node(root->left,x);
        if(root->left->prio>root->prio){
            root=rotate_right(root);
        }
    }else{
        root->right=insert_node(root->right,x);
        if(root->right->prio>root->prio){
            root=rotate_left(root);
        }
    }
    update_size(root);
    return root;
}

int count_less_equal(Node*root,int x){
    if(root==NULL)return 0;
    if(root->val<=x){
        int left_size=root->left?root->left->size:0;
        return left_size+1+count_less_equal(root->right,x);
    }else{
        return count_less_equal(root->left,x);
    }
}

int kth(Node*root,int L,int R, int k){
    int left=L;
    int right=R;
    int ans=-1;

    while(left<=right){
        int mid=left+(right-left)/2;
        int cnt=count_less_equal(root,mid)-count_less_equal(root,L-1);

        if(cnt>=k){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return ans;
}

int main(){
    srand(time(NULL));
    int N;
    scanf("%d",&N);
    Node*root=NULL;
    int*arr=(int*)malloc(N*sizeof(int));
    int t=0;
    for(int i=0;i<N;i++){
        int op;
        scanf("%d",&op);
        if(op==0){
            int S;
            scanf("%d",&S);
            root=insert_node(root,S);
        }else{
            int L,R,k;
            scanf("%d %d %d",&L,&R,&k);
            arr[t++]=kth(root,L,R,k);
        }
    }
    for(int i=0;i<t;i++){
        printf("%d\n",arr[i]);
    }
    free(arr);
    return 0;
}
