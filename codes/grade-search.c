#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Node{
    int val; // 节点存储的值
    int prio; // 随机优先级（用于维护堆结构）
    int size; // 以该节点为根的子树大小
    struct Node*left; // 左子节点指针
    struct Node*right; // 右子节点指针
}Node;

// 创建新节点
Node*create_node(int val){
    Node*new_node=(Node*)malloc(sizeof(Node));
    new_node->val=val;
    new_node->prio=rand();  // 赋予随机优先级
    new_node->size=1;       // 初始大小为1
    new_node->left=new_node->right=NULL;// 初始化子节点为空
    return new_node;
}

// 更新节点子树大小
void update_size(Node*node){
    if(node==NULL)return;
    node->size=1;// 自身计数为1
    // 累加左右子树大小
    if(node->left)node->size+=node->left->size;
    if(node->right)node->size+=node->right->size;
}

// 右旋操作（提升左子节点）
Node*rotate_right(Node*y){
    Node*x=y->left;       // x为y的左子节点
    Node*T2=x->right;     // 保存x的右子树
    x->right=y;           // y成为x的右子节点
    y->left=T2;           // x原来的右子树变为y的左子树
    update_size(y);       // 更新y的大小
    update_size(x);       // 更新x的大小
    return x;             // 返回新的根节点
}

// 左旋操作（提升右子节点）
Node*rotate_left(Node*x){
    Node*y=x->right;// y为x的右子节点
    Node*T2=y->left;// 保存y的左子树
    y->left=x;// x成为y的左子节点
    x->right=T2;// y原来的左子树变为x的右子树
    update_size(x);// 更新x的大小
    update_size(y);// 更新y的大小
    return y;// 返回新的根节点
}

// 插入节点到Treap
Node*insert_node(Node*root,int val){
    if(root==NULL){
        return create_node(val);// 基础情况：创建新节点
    }
    if(val<=root->val){// 插入左子树
        root->left=insert_node(root->left,val);
        // 维护堆性质：若左子节点优先级更高则右旋
        if(root->left->prio>root->prio){
            root=rotate_right(root);
        }
    }else{// 插入右子树
        root->right=insert_node(root->right,val);
        // 维护堆性质：若右子节点优先级更高则左旋
        if(root->right->prio>root->prio){
            root=rotate_left(root);
        }
    }
    update_size(root);// 更新当前节点大小
    return root;
}


// 统计小于等于x的节点数量
int count_less_equal(Node*root,int x){
    if(root==NULL)return 0;
    if(root->val<=x){
        // 当前节点符合条件，累加左子树大小+1+右子树的统计结果
        int left_size=root->left?root->left->size:0;
        return left_size+1+count_less_equal(root->right,x);
    }else{
        // 仅在左子树中查找
        return count_less_equal(root->left,x);
    }
}

// 查询区间[L, R]中的第k小数
int query_kth(Node*root,int L,int R,int k){
    int left=L;
    int right=R;
    int ans=-1;// 初始化答案为-1（未找到）
    // 二分查找数值范围
    while(left<=right){
        int mid=left+(right-left)/2;// 避免溢出的中间值计算
        // 计算在[L, mid]范围内的元素数量
        int cnt=count_less_equal(root,mid)-count_less_equal(root,L-1);
        if(cnt>=k){// 数量足够，尝试更小的值
            ans=mid;
            right=mid-1;
        }else{// 数量不足，需要更大的值
            left=mid+1;
        }
    }
    return ans;// 返回找到的最小满足条件的数
}

int main(){
    srand(time(NULL));// 初始化随机种子
    Node*root=NULL;// Treap根节点
    int N;
    scanf("%d",&N);// 读取操作次数
    int*arr=(int*)malloc(N*sizeof(int));// 存储查询结果
    if(arr==NULL){
        fprintf(stderr,"Memery allocation failed\n");
        return 1;
    }
    int t=0;// 结果数组索引
    for(int i=0;i<N;i++){
        int op;
        scanf("%d",&op);
        if(op==0){// 插入操作
            int S;
            scanf("%d",&S);
            root=insert_node(root,S);
        }else{// 查询操作
            int L,R,k;
            scanf("%d %d %d",&L,&R,&k);
            int res=query_kth(root,L,R,k);
            arr[t++]=res;// 存储结果
        }
    }
     // 输出所有查询结果
    for(int i=0;i<t;i++){
       printf("%d\n",arr[i]);
    }
    free(arr);// 释放内存
    return 0;
}