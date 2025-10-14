#include <stdio.h>
#define N 4

int maze[N][N] = {
    {1, 0, 0, 0},
    {1, 1, 0, 1},
    {0, 1, 0, 0},
    {1, 1, 1, 1}
};

int visited[N][N] = {0};

// Directions: Down, Left, Right, Up
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};

void solveMaze(int x, int y, char path[], int index) {
    // reached destination
    if (x == N - 1 && y == N - 1) {
        path[index] = '\0';
        printf("%s\n", path);
        return;
    }

    // try all directions
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // check validity
        if (newX >= 0 && newY >= 0 && newX < N && newY < N &&
            maze[newX][newY] == 1 && !visited[newX][newY]) {

            visited[x][y] = 1;
            path[index] = dir[i];
            solveMaze(newX, newY, path, index + 1);
            visited[x][y] = 0; // backtrack
        }
    }
}

int main() {
    if (maze[0][0] == 0) {
        printf("No path available\n");
        return 0;
    }

    char path[100];
    printf("All possible paths:\n");
    solveMaze(0, 0, path, 0);

    return 0;
}
