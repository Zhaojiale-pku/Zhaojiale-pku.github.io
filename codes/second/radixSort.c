#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 400

// 简化字符转换函数
int charToIndex(char c) {
    if (c == ' ') return 0;
    return c - 'a' + 1;
}

void radixSort(char words[][MAX_LEN], int count, int d) {
    char buckets[27][MAX_WORDS][MAX_LEN];
    int bucketSize[27];

    for (int pos = d - 1; pos >= 0; pos--) {
        memset(bucketSize, 0, sizeof(bucketSize));
        
        for (int i = 0; i < count; i++) {
            int idx = charToIndex(words[i][pos]);
            strncpy(buckets[idx][bucketSize[idx]], words[i],MAX_LEN);
            buckets[idx][bucketSize[idx]][MAX_LEN-1]='\0';
            bucketSize[idx]++;
        }
        
        int idx = 0;
        for (int i = 0; i < 27; i++) {
            for (int j = 0; j < bucketSize[i]; j++) {
                strcpy(words[idx++], buckets[i][j]);
            }
        }
        
        // 直接打印去除尾部空格的单词
        printf("第 %d 趟排序结果:\n", d - pos);
        for (int i = 0; i < count; i++) {
            char temp[MAX_LEN];
            strcpy(temp,words[i]);

            int len=strlen(temp);
            while(len>0&&temp[len-1]==' '){
                temp[--len]='\0';
            }

            printf("%s",temp);
            if (i < count-1) printf(" ");
        }
        printf("\n----------\n");
    }
}

int main() {
    int count, d = 0;
    char words[MAX_WORDS][MAX_LEN];
    
    printf("请输入单词个数：");
    scanf("%d", &count);

    printf("请输入每个单词（仅小写字母）：\n");
    for (int i = 0; i < count; i++) {
        scanf("%199s", words[i]);
        int len = strlen(words[i]);
        if (len > d) d = len;
    }

    for(int i=0;i<count;i++){
        int len=strlen(words[i]);
        for(int j = len; j < d; j++) {
             words[i][j] = ' ';
        }
        words[i][d] = '\0';
    }

    radixSort(words, count, d);

    printf("最终字典序排序结果：\n");
    for (int i = 0; i < count; i++) {
        int len = strlen(words[i]);
        while (len > 0 && words[i][len-1] == ' ') len--;
        words[i][len] = '\0';
        printf("%s", words[i]);
        if (i < count - 1) printf(" ");
    }
    printf("\n");

    return 0;
}