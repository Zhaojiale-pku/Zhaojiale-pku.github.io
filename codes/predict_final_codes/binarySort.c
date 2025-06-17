#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCKS 100
#define MAX_BLOCK_SIZE 100

typedef struct {
    int maxValue; // 每块最大值
    int blockIndex; // 块编号
} BlockIndex;

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 折半查找目标值所在块
int binarySearchBlock(BlockIndex index[], int blockCount, int target) {
    int left = 0, right = blockCount - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (target <= index[mid].maxValue) {
            if (mid == 0 || target > index[mid - 1].maxValue)
                return index[mid].blockIndex; // 找到所在块
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1; // 不在任何块中
}

// 顺序查找
int sequentialSearch(int block[], int blockSize, int target) {
    for (int i = 0; i < blockSize; ++i) {
        if (block[i] == target) return i;
    }
    return -1;
}

int main() {
    int n, blockSize;
    scanf("%d,%d", &n, &blockSize);
    int blockCount = n / blockSize;

    int blocks[MAX_BLOCKS][MAX_BLOCK_SIZE];
    BlockIndex index[MAX_BLOCKS];

    // 输入每块数据并建立块索引
    for (int i = 0; i < blockCount; ++i) {
        int maxVal = -1;
        for (int j = 0; j < blockSize; ++j) {
            scanf("%d,", &blocks[i][j]);
            if (blocks[i][j] > maxVal)
                maxVal = blocks[i][j];
        }
        index[i].maxValue = maxVal;
        index[i].blockIndex = i;
    }

    // 将块索引按 maxValue 升序排序
    qsort(index, blockCount, sizeof(BlockIndex), compare);

    // 输入要查找的值
    int target;
    printf("请输入要查找的值：");
    scanf("%d", &target);

    // 查找所在块
    int blockId = binarySearchBlock(index, blockCount, target);
    if (blockId == -1) {
        printf("未找到目标值 %d\n", target);
    } else {
        int pos = sequentialSearch(blocks[blockId], blockSize, target);
        if (pos == -1) {
            printf("未找到目标值 %d\n", target);
        } else {
            printf("找到目标值 %d，在第 %d 块的第 %d 个位置\n", target, blockId + 1, pos + 1);
        }
    }

    return 0;
}
