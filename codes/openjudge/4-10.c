#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    char grid[R][C + 1];
    for (int i = 0; i < R; i++) {
        scanf("%s", grid[i]);
    }

    // 处理行方向，找到最小h
    int *fail = (int *)malloc(R * sizeof(int));
    fail[0] = 0;
    for (int i = 1; i < R; i++) {
        int j = fail[i - 1];
        while (j > 0 && strcmp(grid[i], grid[j]) != 0) {
            j = fail[j - 1];
        }
        if (strcmp(grid[i], grid[j]) == 0) {
            j++;
        }
        fail[i] = j;
    }
    int h_candidate = R - fail[R - 1];
    int valid = 1;
    for (int i = h_candidate; i < R; i++) {
        if (strcmp(grid[i], grid[i - h_candidate]) != 0) {
            valid = 0;
            break;
        }
    }
    int h = valid ? h_candidate : R;

    // 处理列方向，找到最小w
    // 预处理每列的字符数组
    char **cols = (char **)malloc(C * sizeof(char *));
    for (int j = 0; j < C; j++) {
        cols[j] = (char *)malloc(R + 1);
        for (int i = 0; i < R; i++) {
            cols[j][i] = grid[i][j];
        }
        cols[j][R] = '\0';
    }

    int w = C;
    for (int current_w = 1; current_w <= C; current_w++) {
        valid = 1;
        for (int j = current_w; j < C; j++) {
            if (memcmp(cols[j], cols[j - current_w], R) != 0) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            w = current_w;
            break;
        }
    }

    // 计算面积
    printf("%d\n", h * w);

    // 释放内存
    free(fail);
    for (int j = 0; j < C; j++) {
        free(cols[j]);
    }
    free(cols);

    return 0;
}