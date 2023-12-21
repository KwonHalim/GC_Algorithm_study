#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y;
} Node;

typedef struct {
    int from, to;
    double distance;
} Edge;

int parent[31];

int find_parent(int x) {
    if (parent[x] != x)
        parent[x] = find_parent(parent[x]);
    return parent[x];
}

void Union(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);
    if (x != y) parent[y] = x;
}


void selectionSort(Edge arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j].distance < arr[min_idx].distance) {
                min_idx = j;
            }
        }
        Edge temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Node Nodes[31];
    Edge edges[1000];

    double result = 0;

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &Nodes[i].x, &Nodes[i].y);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = sqrt((Nodes[i].x - Nodes[j].x) * (Nodes[i].x - Nodes[j].x) + (Nodes[i].y - Nodes[j].y) * (Nodes[i].y - Nodes[j].y));
            edges[cnt].from = i;
            edges[cnt].to = j;
            edges[cnt].distance = distance;
            cnt++;
        }
    }

    selectionSort(edges, cnt);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < cnt; i++) {
        int from = edges[i].from;
        int to = edges[i].to;
        double distance = edges[i].distance;

        if (find_parent(from) != find_parent(to)) {
            Union(from, to);
            result += distance;
        }
    }

    printf("%.2lf\n", result);

    return 0;
}