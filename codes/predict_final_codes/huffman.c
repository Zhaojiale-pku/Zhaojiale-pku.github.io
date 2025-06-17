#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 27
#define MAX_NODES (2 * MAX_CHAR - 1)
#define MAX_CODE_LEN 100

// Huffman 树结点
typedef struct {
    char ch;
    int freq;
    int parent, left, right;
} HuffmanNode;

// 编码表项
typedef struct {
    char ch;
    char code[MAX_CODE_LEN];
} HuffmanCode;

HuffmanNode huffTree[MAX_NODES];
HuffmanCode huffCodes[MAX_CHAR];
int charCount = MAX_CHAR;

// 获取两个最小权值的节点下标
void selectMin(int n, int *s1, int *s2) {
    int i;
    *s1 = *s2 = -1;
    for (i = 0; i < n; ++i) {
        if (huffTree[i].parent == -1) {
            if (*s1 == -1 || huffTree[i].freq < huffTree[*s1].freq) {
                *s2 = *s1;
                *s1 = i;
            } else if (*s2 == -1 || huffTree[i].freq < huffTree[*s2].freq) {
                *s2 = i;
            }
        }
    }
}

// 构建 Huffman 树
void buildHuffmanTree(int freq[]) {
    int n = charCount;
    for (int i = 0; i < n; ++i) {
        huffTree[i].ch = (i == 26) ? ' ' : 'a' + i;
        huffTree[i].freq = freq[i];
        huffTree[i].parent = huffTree[i].left = huffTree[i].right = -1;
    }

    for (int i = n; i < 2 * n - 1; ++i) {
        int s1, s2;
        selectMin(i, &s1, &s2);
        huffTree[i].ch = '\0';
        huffTree[i].freq = huffTree[s1].freq + huffTree[s2].freq;
        huffTree[i].left = s1;
        huffTree[i].right = s2;
        huffTree[i].parent = -1;
        huffTree[s1].parent = huffTree[s2].parent = i;
    }
}

// 生成编码表
void generateCodes() {
    char tempCode[MAX_CODE_LEN];
    int n = charCount;
    for (int i = 0; i < n; ++i) {
        int current = i, parent;
        int len = 0;
        while ((parent = huffTree[current].parent) != -1) {
            if (huffTree[parent].left == current)
                tempCode[len++] = '0';
            else
                tempCode[len++] = '1';
            current = parent;
        }
        tempCode[len] = '\0';
        // 反转编码
        for (int j = 0; j < len / 2; ++j) {
            char tmp = tempCode[j];
            tempCode[j] = tempCode[len - 1 - j];
            tempCode[len - 1 - j] = tmp;
        }
        huffCodes[i].ch = huffTree[i].ch;
        strcpy(huffCodes[i].code, tempCode);
    }
}

// 查找字符的编码
char* getCode(char ch) {
    for (int i = 0; i < charCount; ++i) {
        if (huffCodes[i].ch == ch)
            return huffCodes[i].code;
    }
    return NULL;
}

// 查找编码对应的字符
char decodeChar(const char* binStr, int *start, int root) {
    int node = root;
    while (huffTree[node].left != -1 && huffTree[node].right != -1) {
        if (binStr[*start] == '0')
            node = huffTree[node].left;
        else
            node = huffTree[node].right;
        (*start)++;
    }
    return huffTree[node].ch;
}

// 编码函数
void encode(const char* str, char* encoded) {
    encoded[0] = '\0';
    for (int i = 0; str[i]; ++i) {
        strcat(encoded, getCode(str[i]));
    }
}

// 解码函数
void decode(const char* binStr, char* decoded, int root) {
    int index = 0, pos = 0;
    while (binStr[index]) {
        decoded[pos++] = decodeChar(binStr, &index, root);
    }
    decoded[pos] = '\0';
}

// 主函数示例
int main() {
    // 示例频率：a-z + 空格（根据题意可修改）
    int freq[MAX_CHAR] = {
        5, 9, 12, 13, 16, 45, 5, 6, 7, 8, 9, 10, 11,
        12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24,
        30 // 空格的频率
    };

    buildHuffmanTree(freq);
    generateCodes();

    printf("Huffman 编码表:\n");
    for (int i = 0; i < charCount; ++i)
        printf("'%c': %s\n", huffCodes[i].ch, huffCodes[i].code);

    char inputStr[100] = "abc xyz";
    char encodedStr[1000], decodedStr[100];

    encode(inputStr, encodedStr);
    printf("\n原始字符串: %s\n", inputStr);
    printf("编码结果: %s\n", encodedStr);

    decode(encodedStr, decodedStr, 2 * charCount - 2);
    printf("解码结果: %s\n", decodedStr);

    return 0;
}
