#include<stdio.h>

void QuickSort(int arr[],int L,int R){
    if(R<=L)return;
    int i=L;
    int j=R;
    int pivot=arr[i];

    while(i!=j){
        while(i<j&&arr[j]>=pivot)j--;
        if(i<j)arr[i++]=arr[j];

        while(i<j&&arr[i]<=pivot)i++;
        if(i<j)arr[j--]=arr[i];
    }

    arr[i]=pivot;

    QuickSort(arr,L,i-1);
    QuickSort(arr,i+1,R);
}