#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int maze[MAX][MAX];
int visited[MAX][MAX];
int preX[MAX][MAX];
int preY[MAX][MAX];
int n, m;
int sx, sy, ex, ey;

int dir[4][2] = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point data[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, Point p) {
    q->data[q->rear++] = p;
}

Point dequeue(Queue *q) {
    return q->data[q->front++];
}

void printPath(int x, int y) {
    if (x == sx && y == sy) {
        printf("(%d,%d)", x, y);
        return;
    }
    printPath(preX[x][y], preY[x][y]);
    printf(" -> (%d,%d)", x, y);
}

int bfs() {
    Queue q;
    initQueue(&q);

    Point start = {sx, sy};
    enqueue(&q, start);
    visited[sx][sy] = 1;

    while (!isEmpty(&q)) {
        Point cur = dequeue(&q);
        if (cur.x == ex && cur.y == ey) {
            printPath(ex, ey);
            printf("\n");
            return 1;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dir[i][0];
            int ny = cur.y + dir[i][1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                maze[nx][ny] == 0 && !visited[nx][ny]) {
                Point next = {nx, ny};
                enqueue(&q, next);
                visited[nx][ny] = 1;
                preX[nx][ny] = cur.x;
                preY[nx][ny] = cur.y;
            }
        }
    }

    printf("No path found.\n");
    return 0;
}

int main() {
    printf("请输入迷宫的行数和列数: ");
    scanf("%d %d", &n, &m);
    
    printf("请输入迷宫地图（0表示通路，1表示墙）:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maze[i][j]);

    printf("请输入起点坐标 (行 列): ");
    scanf("%d %d", &sx, &sy);
    printf("请输入终点坐标 (行 列): ");
    scanf("%d %d", &ex, &ey);

    if (maze[sx][sy] != 0 || maze[ex][ey] != 0) {
        printf("起点或终点不是通路，无法搜索。\n");
        return 0;
    }

    printf("寻找最短路径...\n");
    bfs();
    return 0;
}
