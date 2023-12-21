#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define INF INT_MAX

int MinimumCost(int cost[], int n, int W) {
    // val[]�� weight[] �迭
    // val[] �迭�� 'i' ų�α׷� ������ �� ���� ����� �����մϴ�.
    // weight[] �迭�� ������ �� ���� ���Ը� ��Ÿ���ϴ�.
    int val[100], weight[100]; // �ִ� ũ��� ����

    // ���� cost[] �迭�� Ž���ϰ� ��� �Ұ����� ��Ŷ�� �ǳʶٸ�,
    // val[] �迭�� weight[] �迭�� �����մϴ�. size ������ ��� ������ ��Ŷ ���� ��Ÿ���ϴ�.
    int size = 0;
    for (int i = 0; i < n; i++) {
        if (cost[i] != -1) {
            val[size] = cost[i];
            weight[size] = i + 1;
            size++;
        }
    }
    for (int i = 0; i < size; i++) {
        printf("val:%d, weight:%d\n", val[i], weight[i]);
    }
    n = size;
    int min_cost[100][100]; // �ִ� ũ��� ����

    // 0��° ���� ���Ѵ�� ä��ϴ�.
    for (int i = 0; i <= W; i++)
        min_cost[0][i] = INF;

    // 0��° ���� 0���� ä��ϴ�.
    for (int i = 1; i <= n; i++)
        min_cost[i][0] = 0;

    // ���� �� ���Կ� ���� �ϳ��� Ȯ���ϰ� ���ǿ� ���� ����� ä��ϴ�.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            // weight[i-1]>j�� ������ �뷮�� �������� ���Ժ��� ������ �ǹ��մϴ�.
            if (weight[i - 1] > j)
                min_cost[i][j] = min_cost[i - 1][j];
            // ���⼭ �츮�� �������� �����ϰų� �������� �ʴ� �� �߿��� �ּ� ����� ����ϴ�.
            else
                min_cost[i][j] = min(min_cost[i - 1][j],min_cost[i][j - weight[i - 1]] + val[i - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < W; j++) {
            if (min_cost[i][j]>10000 || min_cost[i][j]<-1)
                continue;
            printf("%d ", min_cost[i][j]);
        }
        printf("\n");
    }

    // ��Ȯ�� ���� W�� �־��� ���Է� ���� �� ���� ���
    if(min_cost[n][W] == INT_MAX) {
        return -1;
    }
    else {
         return min_cost[n][W];
    }

}

// �׽�Ʈ ���̽��� �����ϴ� ����̹� ���α׷�
int main() {
    int cost[] = { 10,20,5,20,50 };
    int W = 30;
    int n = sizeof(cost) / sizeof(cost[0]);

    int result = MinimumCost(cost, n, W);
    printf("%d\n", result);

    return 0;
}
