#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int*b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void heapify_down(int arr[],int size,int i){
	int smallest=i;
	int left=2*i+1;
	int right=2*i+2;

	if(left<size&&arr[left]<arr[smallest]){
		smallest=left;
	}
	if(right<size&&arr[right]<arr[smallest]){
		smallest=right;
	}
	if(smallest!=i){
		swap(&arr[smallest],&arr[i]);
		heapify_down(arr,size,smallest);
	}
}

void build_min_heap(int arr[],int size){
	for(int i=size/2-1;i>=0;i--){
		heapify_down(arr,size,i);
	}
}

void heapify_up(int arr[],int index){
	while(index>0){
		int parent=(index-1)/2;
		if(arr[index]<arr[parent]){
			swap(&arr[parent],&arr[index]);
			index=parent;
		}
		else{
			break;
		}
	}
}

int main(){
	int N,M;
	scanf("%d %d",&N,&M);

	int*freq=(int*)calloc(N,sizeof(int));
	int*active_chars=(int*)malloc(N*sizeof(int));
	int active_size=0;
	int output[100000];
	int k=0;

	for(int i=0;i<M;i++){
		int op;
		scanf("%d",&op);
		if(op!=0){
			int c=op;
			if(c<1||c>N) continue;
			int idx=c-1;

			if(freq[idx]==0){
				active_chars[active_size++]=c;
			}
			freq[idx]++;
		}
		else{
			if(active_size==0){
				output[k++]=1;
				continue;
			}
			int size=active_size+1;
			int*temp=(int*)malloc(size*sizeof(int));
			temp[0]=1;

			for(int j=0;j<active_size;j++){
				temp[j+1]=freq[active_chars[j]-1];
			}

			build_min_heap(temp,size);
			int sum=0;
			int len=size;

			while(len>1){
				int a=temp[0];
				temp[0]=temp[--len];
				heapify_down(temp,len,0);

				int b=temp[0];
				temp[0]=temp[--len];
				heapify_down(temp,len,0);

				sum+=a+b;
				temp[len++]=a+b;
				heapify_up(temp,len-1);
			}
			output[k++]=sum;
			free(temp);
		}
	}

	free(freq);
	free(active_chars);
	for(int i=0;i<k;i++){
		printf("%d\n",output[i]);
	}
	return 0;
}

