#include<stdio.h>
#include<stdlib.h>
//直接插入
void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;

        while(j>=0&&arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

//折半插入排序函数
void binaryInsertionSort(int arr[],int n){
    int i,j,key,low,mid,high;
    
    for(i=1;i<n;i++){
        low=0;
        high=i-1;
        key=arr[i];

        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]>key){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }

        for(j=i-1;j>=low;j--){
            arr[j+1]=arr[j];
        }
        arr[low]=key;
    }
}

//2-路插入排序
void twoWayInsertionSort(int a[],int n){
    int d[n];
    int first=0,last=0;
    d[0]=a[0];

    for(int i=1;i<n;i++){
        if(a[i]<d[first]){
            first=(first-1+n)%n;
            d[first]=a[i];
        }else if(a[i]>=d[last]){
            last=(last+1)%n;
            d[last]=a[i];
        }else{
            int j=last;
            last=(last+1)%n;
            while(a[i]<d[j]){
                d[(j+1)%n]=d[j];
                j=(j-1+n)%n;
            }
            d[j+1]=a[i];
        }
    }

    int idx=first;
    for(int i=0;i<n;i++){
        a[i]=d[(i+idx)%n];
    }
}

//链表插入排序
typedef int KeyType;
typedef int DataType;

struct Node{
    KeyType key;
    DataType info;
    struct Node*next;
};
typedef struct Node ListNode,*LinkList;

void ListSort(LinkList plist){
    ListNode *head,*pre,*p,*q,*now;
    head=plist;
    pre=head->next;
    now=pre->next;
    
    if(pre==NULL||now==NULL){
        return;
    }

    while(now!=NULL){
        q=head;
        p=head->next;
        while(p!=now&&p->key<=now->key){
            q=p;
            p=p->next;
        }

        if(p==now){
            pre=pre->next;
            now=pre->next;
            continue;
        }

        pre->next=now->next;
        q->next=now;
        now->next=p;

        now=pre->next;
    }
}

//shell排序
typedef struct{
    int key;
}RecordNode;

typedef struct{
    RecordNode *record;
    int n;
}SortObject;

void shellSort(SortObject*pv,int d){
    int i,j,inc;
    RecordNode temp;

    for(inc=d;inc>0;inc/=2){
        for(i=inc;i<pv->n;i++){
            temp=pv->record[i];
            j=i-inc;
            while(j>=0&&temp.key<pv->record[j].key){
                pv->record[j+inc]=pv->record[j];
                j-=inc;
            }
            pv->record[j+inc]=temp;
        }
    }
}