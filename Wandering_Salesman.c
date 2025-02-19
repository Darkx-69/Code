#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the minimum of two integers
int mn(int a, int b)
 {
    return a < b ? a : b;
}

// Recursive function to solve the Traveling Salesman Problem using backtracking
int tsp(int **g, int s, int c, int *v, int count, int cost, int n) {
    // Base case: If all cities have been visited, return the cost of returning to the start
    if (count == n) 
        return cost + g[c][s];

    int m = INT_MAX; // Initialize minimum cost to maximum integer value

    // Iterate through all cities
    for (int i = 0; i < n; i++) {
        // If city 'i' has not been visited
        if (!v[i]) {
            v[i] = 1; // Mark city 'i' as visited

            // Recursive call to explore the next city
            int nc = tsp(g, s, i, v, count + 1, cost + g[c][i], n);

            m = mn(m, nc); // Update the minimum cost

            v[i] = 0; // Unmark city 'i' (backtrack)
        }
    }
    return m; // Return the minimum cost found
}

int main() {
    int n; // Number of cities
    printf("Cities: ");
    scanf("%d", &n);

    // Allocate memory for the adjacency matrix 'g'
    int **g = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) 
        g[i] = (int *)malloc(n * sizeof(int));

    printf("Matrix:\n");
    // Read the adjacency matrix from the user
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            scanf("%d", &g[i][j]);

    int s; // Starting city
    printf("Start: ");
    scanf("%d", &s);

    // Allocate memory for the visited array 'v'
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
        v[i] = 0; // Initialize visited array to 0
    v[s] = 1; // Mark the starting city as visited

    // Calculate the shortest distance using the tsp function
    int cost = tsp(g, s, s, v, 1, 0, n);
    printf("Shortest Distance: %d\n", cost);

    // Free allocated memory
    free(v);
    for (int i = 0; i < n; i++) 
        free(g[i]);
    free(g);

    return 0;
}
