#include<stdio.h>
#include<string.h>
#include<memory.h>

#define MAX_WORDS 100
#define MAX_LEN 400

int charToIndex(char c){
    if(c==' ')return 0;
    return c-'a'+1;
}

char words[MAX_WORDS][MAX_LEN];

void radixSort(int count,int d){
    char buckets[27][MAX_WORDS][MAX_LEN];
    int bucketSize[27];

    for(int pos=d-1;pos>=0;pos--){
        memset(bucketSize,0,sizeof(bucketSize));

        for(int i=0;i<count;i++){
            int idx=charToIndex(words[i][pos]);
            strcpy(buckets[idx][bucketSize[idx]],words[i]);
            bucketSize[idx]++;
        }

        memset(words,0,sizeof(words));

        int idx=0;

        for(int i=0;i<27;i++){
            for(int j=0;j<bucketSize[i];j++){
                strcpy(words[idx++],buckets[i][j]);
            }
        }
        printf("%d\n",d-pos);

        for(int i=0;i<count;i++){
            char temp[MAX_LEN];
            strcpy(temp,words[i]);
            int len=strlen(temp);
            while(len>0&&temp[len-1]==' ')len--;
            temp[len]='\0';
            printf("%s",temp);
            if(i<count-1)printf(" ");
        }
        printf("\n");
    }
}

int main(){
    int count,d=0;
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf("%s",words[i]);
        int len=strlen(words[i]);
        if(len>d)d=len;
    }

    for(int i=0;i<count;i++){
        int len=strlen(words[i]);
        for(int j=len;j<d;j++){
            words[i][j]=' ';
        }
        words[i][d]='\0';
    }

    radixSort(count,d);

    printf("final results:\n");

    for(int i=0;i<count;i++){
        int len=strlen(words[i]);
        while(len>0&&words[i][len-1]==' ')len--;
        words[i][len]='\0';
        printf("%s",words[i]);
        if(i<count-1)printf(" ");
    }
    return 0;
}