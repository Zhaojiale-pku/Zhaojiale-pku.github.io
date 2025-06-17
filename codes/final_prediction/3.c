#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define CHAR_COUNT 27 // 'a'-'z' + space

// 定义Huffman树节点
typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

// 定义最小堆结构
typedef struct {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

// 创建新节点
MinHeapNode* newNode(char data, unsigned freq) {
    MinHeapNode* node = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// 创建最小堆
MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

// 交换两个节点
void swapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// 堆化操作
void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// 检查堆大小
int isSizeOne(MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// 提取堆中最小值节点
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// 插入堆
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// 构建最小堆
void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// 创建并构建最小堆
MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// 构建Huffman树
MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq); // $表示内部节点
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// 将编码存储到数组中
void storeCodes(MinHeapNode* root, char *str, int top, char **huffmanCodes) {
    if (root->left) {
        str[top] = '0';
        storeCodes(root->left, str, top + 1, huffmanCodes);
    }
    if (root->right) {
        str[top] = '1';
        storeCodes(root->right, str, top + 1, huffmanCodes);
    }
    if (!root->left && !root->right) {
        str[top] = '\0';
        int index = (root->data == ' ') ? 26 : root->data - 'a';
        huffmanCodes[index] = (char*)malloc((strlen(str) + 1) * sizeof(char));
        strcpy(huffmanCodes[index], str);
    }
}

// 生成Huffman编码
void generateHuffmanCodes(MinHeapNode* root, char **huffmanCodes) {
    char str[MAX_TREE_HT];
    int top = 0;
    storeCodes(root, str, top, huffmanCodes);
}

// Huffman编码函数
char* huffmanEncode(char *input, char **huffmanCodes) {
    int length = strlen(input);
    int totalLen = 0;
    
    // 计算总长度
    for (int i = 0; i < length; i++) {
        int index = (input[i] == ' ') ? 26 : input[i] - 'a';
        totalLen += strlen(huffmanCodes[index]);
    }
    
    char *encodedStr = (char*)malloc((totalLen + 1) * sizeof(char));
    encodedStr[0] = '\0';
    
    // 拼接编码字符串
    for (int i = 0; i < length; i++) {
        int index = (input[i] == ' ') ? 26 : input[i] - 'a';
        strcat(encodedStr, huffmanCodes[index]);
    }
    
    return encodedStr;
}

// Huffman解码函数
char* huffmanDecode(char *encodedStr, MinHeapNode *root) {
    char *decodedStr = (char*)malloc((strlen(encodedStr) + 1) * sizeof(char));
    int idx = 0;
    MinHeapNode *current = root;
    
    for (int i = 0; encodedStr[i]; i++) {
        current = (encodedStr[i] == '0') ? current->left : current->right;
        if (!current->left && !current->right) {
            decodedStr[idx++] = current->data;
            current = root;
        }
    }
    decodedStr[idx] = '\0';
    return decodedStr;
}

int main() {
    int freq[CHAR_COUNT];
    char data[] = {
        'a','b','c','d','e','f','g','h','i','j','k','l','m',
        'n','o','p','q','r','s','t','u','v','w','x','y','z',' '
    };
    
    // 输入27个字符的频率
    printf("请按顺序输入27个字符的频率（a-z + 空格）:\n");
    for (int i = 0; i < CHAR_COUNT; i++) {
        scanf("%d", &freq[i]);
    }
    
    // 构建Huffman树
    MinHeapNode *root = buildHuffmanTree(data, freq, CHAR_COUNT);
    
    // 生成Huffman编码
    char *huffmanCodes[CHAR_COUNT];
    generateHuffmanCodes(root, huffmanCodes);
    
    // 输出字符和编码
    printf("\n字符 Huffman编码:\n");
    for (int i = 0; i < CHAR_COUNT; i++) {
        char c = (i == 26) ? ' ' : 'a' + i;
        printf("%c: %s\n", c, huffmanCodes[i]);
    }
    
    // 输入要编码的字符串
    char input[100];
    printf("\n请输入要编码的字符串（小写字母和空格）:\n");
    getchar(); // 消耗换行符
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // 移除换行符
    
    // 编码字符串
    char *encodedStr = huffmanEncode(input, huffmanCodes);
    printf("\n编码结果:\n%s\n", encodedStr);
    
    // 解码字符串
    char *decodedStr = huffmanDecode(encodedStr, root);
    printf("\n解码结果:\n%s\n", decodedStr);
    
    // 验证解码是否匹配原输入
    if (strcmp(input, decodedStr) == 0) {
        printf("\n解码字符串与原输入匹配\n");
    } else {
        printf("\n解码字符串与原输入不匹配\n");
    }
    
    // 释放内存
    free(encodedStr);
    free(decodedStr);
    for (int i = 0; i < CHAR_COUNT; i++) {
        free(huffmanCodes[i]);
    }
    
    return 0;
}