#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 100

struct State {
    int farmer, wolf, goat, cabbage;
};

// 记录路径
struct State path[MAX_DEPTH];
int visited[16]; // 状态空间最多2^4=16种

int encode(struct State s) {
    return (s.farmer << 3) | (s.wolf << 2) | (s.goat << 1) | s.cabbage;
}

int is_valid(struct State s) {
    if (s.farmer != s.wolf && s.wolf == s.goat) return 0;
    if (s.farmer != s.goat && s.goat == s.cabbage) return 0;
    return 1;
}

int is_goal(struct State s) {
    return s.farmer == 1 && s.wolf == 1 && s.goat == 1 && s.cabbage == 1;
}

void print_state(struct State s) {
    printf("农夫:%d 狼:%d 羊:%d 菜:%d\n", s.farmer, s.wolf, s.goat, s.cabbage);
}

void dfs(struct State s, int depth) {
    if (!is_valid(s)) return;
    if (visited[encode(s)]) return;

    visited[encode(s)] = 1;
    path[depth] = s;

    if (is_goal(s)) {
        printf("找到一条解路径：\n");
        for (int i = 0; i <= depth; ++i) {
            print_state(path[i]);
        }
        printf("\n");
        return;
    }

    struct State next;

    // 农夫单独过河
    next = s;
    next.farmer = 1 - s.farmer;
    dfs(next, depth + 1);

    // 农夫带狼
    if (s.farmer == s.wolf) {
        next = s;
        next.farmer = 1 - s.farmer;
        next.wolf = 1 - s.wolf;
        dfs(next, depth + 1);
    }

    // 农夫带羊
    if (s.farmer == s.goat) {
        next = s;
        next.farmer = 1 - s.farmer;
        next.goat = 1 - s.goat;
        dfs(next, depth + 1);
    }

    // 农夫带白菜
    if (s.farmer == s.cabbage) {
        next = s;
        next.farmer = 1 - s.farmer;
        next.cabbage = 1 - s.cabbage;
        dfs(next, depth + 1);
    }

    visited[encode(s)] = 0; // 可回溯
}

int main() {
    struct State start = {0, 0, 0, 0}; // 初始都在左岸
    memset(visited, 0, sizeof(visited));
    dfs(start, 0);
    return 0;
}
