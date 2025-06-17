#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LEN 1000
#define MAX_KEYWORDS 100
#define MAX_OCCURRENCES 100

// 存储关键词及其出现位置的结构体
typedef struct {
    char word[50];
    int positions[MAX_OCCURRENCES];
    int count;
} KeywordIndex;

// 在文本中查找关键词出现的位置（逐字符匹配）
void findOccurrences(const char *text, KeywordIndex *kword) {
    int textLen = strlen(text);
    int wordLen = strlen(kword->word);
    kword->count = 0;

    for (int i = 0; i <= textLen - wordLen; i++) {
        int match = 1;
        for (int j = 0; j < wordLen; j++) {
            if (text[i + j] != kword->word[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            if (kword->count < MAX_OCCURRENCES) {
                kword->positions[kword->count++] = i;
            }
        }
    }
}

// 主程序
int main() {
    char text[MAX_TEXT_LEN];
    KeywordIndex keywords[MAX_KEYWORDS];
    int keywordCount;

    // 输入主文本
    printf("请输入主文本（不含换行）:\n");
    fgets(text, MAX_TEXT_LEN, stdin);
    text[strcspn(text, "\n")] = '\0'; // 去掉换行符

    // 输入关键词数量
    printf("请输入关键词数量: ");
    scanf("%d", &keywordCount);
    getchar(); // 清除换行符

    // 输入每个关键词
    for (int i = 0; i < keywordCount; i++) {
        printf("请输入第 %d 个关键词: ", i + 1);
        fgets(keywords[i].word, sizeof(keywords[i].word), stdin);
        keywords[i].word[strcspn(keywords[i].word, "\n")] = '\0'; // 去掉换行符
    }

    // 查找并打印关键词索引
    printf("\n关键词索引表:\n");
    for (int i = 0; i < keywordCount; i++) {
        findOccurrences(text, &keywords[i]);

        printf("关键词 \"%s\" 出现次数: %d\n位置：", keywords[i].word, keywords[i].count);
        for (int j = 0; j < keywords[i].count; j++) {
            printf("%d ", keywords[i].positions[j]);
        }
        printf("\n");
    }

    return 0;
}
