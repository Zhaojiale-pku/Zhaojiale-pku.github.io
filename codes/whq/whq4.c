#include<stdio.h>
#include<string.h>

int is_special(int num){
	char str[20];
	sprintf(str,"%d",num);
	int len=strlen(str);
	for(int i=0;i<len;i++){
		int digit=str[i]-'0';
		if((i%2==0&&digit%2==0)||(i%2==1&&digit%2==1)){
			return 0;
		}
	}
	return 1;
}

int main(){
	int n;
	scanf("%d",&n);
	int nums[100];
	for(int i=0;i<n;i++){
		scanf("%d",&nums[i]);
	}
	int special_count=0;
	int special_nums[100];
	for(int i=0;i<n;i++){
		if(is_special(nums[i])){
			special_nums[special_count++]=nums[i];
		}
	}
	printf("%d\n",special_count);
	if(special_count>0){
		for(int i=0;i<special_count;i++){
			if(i>0){
				printf(" ");
			}
			printf("%d",special_nums[i]);
		}
		printf("\n");
	}else{
		printf("***\n");
	}
	return 0;
}