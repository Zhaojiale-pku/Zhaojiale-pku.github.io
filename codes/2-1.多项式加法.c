#include <stdio.h>
#include <stdlib.h>

#define MAX_DEGREE 1000  // 最大指数值（根据题意可设大些）

int compare(const void *a, const void *b) {
    return *(int *)b - *(int *)a; // 降序排列
}

int main() {
    int n;
    scanf("%d", &n); // 多项式组数

    while (n--) {
        int coef[MAX_DEGREE] = {0}; // 初始化所有幂次的系数为0
        int x, y;

        // 读入一组多项式（两个多项式加在一起）
        int count = 0;
        for (int i = 0; i < 2; ++i) {
            while (1) {
                scanf("%d %d", &x, &y);
                if (y<0) break;
                coef[y] += x; // 同幂次项相加
                if (coef[y] == x) count++; // 首次出现该幂次
            }
        }

        // 统计所有非零项的指数，排序
        int powers[MAX_DEGREE];
        int idx = 0;
        for (int i = 0; i < MAX_DEGREE; ++i) {
            if (coef[i] != 0) {
                powers[idx++] = i;
            }
        }

        qsort(powers, idx, sizeof(int), compare); // 指数降序排序

        printf("[ %d %d ]", coef[powers[0]], powers[0]);
        for (int i = 1; i < idx; ++i) {
            printf(" [ %d %d ]", coef[powers[i]], powers[i]);
        }
        printf("\n");
    }

    return 0;
}
