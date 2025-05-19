#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 100000  // 修正1：扩大幂次范围
#define MAX_GROUPS 100

// 降序排序比较函数
int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

typedef struct {
    int coef[MAX_DEGREE];  // 修正1：支持更大幂次
} PolyResult;

int main() {
    int n;
    scanf("%d", &n);

    PolyResult results[MAX_GROUPS];
    int *group_powers[MAX_GROUPS];  // 修正3：动态内存分配
    int group_power_counts[MAX_GROUPS] = {0};

    for (int g = 0; g < n; ++g) {
        // 初始化系数数组
        for (int i = 0; i < MAX_DEGREE; ++i)
            results[g].coef[i] = 0;

        // 读取两个多项式
        for (int i = 0; i < 2; ++i) {
            while (1) {
                int x, y;
                if (scanf("%d %d", &x, &y) != 2) break;
                if (y < 0) break;
                if (y >= MAX_DEGREE) continue;  // 过滤超大幂次
                results[g].coef[y] += x;
            }
        }

        // 动态分配内存存储非零项
        group_powers[g] = malloc(MAX_DEGREE * sizeof(int));
        int idx = 0;
        for (int i = 0; i < MAX_DEGREE; ++i) {
            if (results[g].coef[i] != 0) {
                group_powers[g][idx++] = i;
            }
        }
        group_power_counts[g] = idx;

        // 降序排序
        qsort(group_powers[g], idx, sizeof(int), compare);
    }

    // 输出结果
    for (int g = 0; g < n; ++g) {
        int t=group_powers[g][0];
        printf("[ %d %d ]",results[g].coef[t],t);
        for (int i = 1; i < group_power_counts[g]; ++i) {
            int p = group_powers[g][i];
            printf(" [ %d %d ]", results[g].coef[p], p);  // 修正2：去除多余空格
        }
        printf("\n");
        free(group_powers[g]);  // 释放动态内存
    }

    return 0;
}
