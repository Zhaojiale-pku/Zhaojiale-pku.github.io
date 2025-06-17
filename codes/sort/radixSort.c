#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_WORDS 1000
#define MAX_LEN 100
#define RADIX 27

int char_to_index(char c){
    if(c==' ')
        return 0;
    return c-'a'+1;
}

void pad_words(char words[][MAX_LEN],int n,int d){
    for(int i=0;i<n;i++){
        int len=strlen(words[i]);
        for(int j=len;j<d;++j){
            words[i][j]=' ';
        }
        words[i][d]='\0';
    }
}

void radix_sort(char words[][MAX_LEN],int n,int d){
    char temp[MAX_WORDS][MAX_LEN];
    for(int pos=d-1;pos>=0;--pos){
        int count[RADIX]={0};

        for(int i=0;i<n;++i){
            int idx=char_to_index(words[i][pos]);
            count[idx]++;
        }

        int start[RADIX];
        start[0]=0;
        for(int i=1;i<RADIX;++i){
            start[i]=start[i-1]+count[i-1];
        }

        for(int i=0;i<n;++i){
            int idx=char_to_index(words[i][pos]);
            strcpy(temp[start[idx]++],words[i]);
        }

        for(int i=0;i<n;++i){
            strcpy(words[i],temp[i]);
        }
    }
}

int main(){
    int n,d;
    char words[MAX_WORDS][MAX_LEN];

    printf("输入单词数量和最大长度d（所有单词将补齐到这个长度）:\n");
    scanf("%d %d", &n, &d);
    printf("输入每个单词（小写字母组成）:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%s", words[i]);
    }

    pad_words(words, n, d);
    radix_sort(words, n, d);

    printf("排序结果为:\n");
    for (int i = 0; i < n; ++i) {
        // 去掉尾部空格再打印
        int len = d;
        while (len > 0 && words[i][len - 1] == ' ')
            len--;
        words[i][len] = '\0';
        printf("%s\n", words[i]);
    }

    return 0;
}
