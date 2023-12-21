#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 30

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int n, int graph[MAX_CITIES][MAX_CITIES], int mask, int pos, int dp[MAX_CITIES][1 << MAX_CITIES]) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int minDistance = INT_MAX;
    for (int i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            int newDistance = graph[pos][i] + tsp(n, graph, mask | (1 << i), i, dp);
            minDistance = min(minDistance, newDistance);
        }
    }

    return dp[pos][mask] = minDistance;
}

void printShortestPath(int n, int graph[MAX_CITIES][MAX_CITIES]) {
    int dp[MAX_CITIES][1 << MAX_CITIES];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    int shortestDistance = tsp(n, graph, 1, 0, dp);
    printf("Shortest Distance: %d\n", shortestDistance);
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[MAX_CITIES][MAX_CITIES];

    printf("Enter the distances between cities:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n");

    printShortestPath(n, graph);

    return 0;
}

