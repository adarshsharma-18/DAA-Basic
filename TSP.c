#include <stdio.h>
#include <limits.h>

#define MAX_N 10 // Maximum value of N

// Function to find minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to solve the Traveling Salesman Problem
int tsp(int graph[MAX_N][MAX_N], int n) {
    int DP[1 << MAX_N][MAX_N];

    // Initialize DP table
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            DP[i][j] = INT_MAX;
        }
    }

    // Base case: when only one city is visited
    for (int i = 0; i < n; i++) {
        DP[1 << i][i] = graph[0][i];
    }

    // Iterate over all subsets of cities
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                for (int j = 0; j < n; j++) {
                    if ((mask & (1 << j)) && i != j) {
                        DP[mask][i] = min(DP[mask][i], DP[mask ^ (1 << i)][j] + graph[j][i]);
                    }
                }
            }
        }
    }

    // Return the minimum cost of visiting all cities
    int minCost = INT_MAX;
    for (int i = 1; i < n; i++) {
        minCost = min(minCost, DP[(1 << n) - 1][i] + graph[i][0]);
    }
    return minCost;
}

int main() {
    int n;
    printf("Enter the number of cities (N): ");
    scanf("%d", &n);

    int graph[MAX_N][MAX_N];
    printf("Enter the cost matrix for the cities:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int minCost = tsp(graph, n);
    printf("Minimum cost of traveling all cities: %d\n", minCost);

    return 0;
}
