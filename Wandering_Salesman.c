#include <stdio.h>
#include <stdlib.h>

// Function to check if a cell is valid and land
int isValid(int row, int col, int m, int n, int** grid, int** visited) {
    return (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 1 && !visited[row][col]);
}

// DFS function to mark all connected land cells as visited
void dfs(int row, int col, int m, int n, int** grid, int** visited) {
    visited[row][col] = 1;
    int dr[] = {-1, 0, 1, 0}; // Directions: up, right, down, left
    int dc[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + dr[i];
        int newCol = col + dc[i];
        if (isValid(newRow, newCol, m, n, grid, visited)) {
            dfs(newRow, newCol, m, n, grid, visited);
        }
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    // Allocate memory for the grid
    int** grid = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        grid[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Allocate memory for the visited array
    int** visited = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        visited[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            visited[i][j] = 0;
        }
    }

    int islandCount = 0;

    // Iterate through the grid and find islands
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                dfs(i, j, m, n, grid, visited);
                islandCount++;
            }
        }
    }

    printf("%d\n", islandCount);

    // Free allocated memory
    for (int i = 0; i < m; i++) {
        free(grid[i]);
        free(visited[i]);
    }
    free(grid);
    free(visited);

    return 0;
}