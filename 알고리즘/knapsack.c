#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define INF INT_MAX

int MinimumCost(int cost[], int n, int W) {
    // val[]와 weight[] 배열
    // val[] 배열은 'i' 킬로그램 오렌지 한 개의 비용을 저장합니다.
    // weight[] 배열은 오렌지 한 개의 무게를 나타냅니다.
    int val[100], weight[100]; // 최대 크기로 선언

    // 원래 cost[] 배열을 탐색하고 사용 불가능한 패킷은 건너뛰며,
    // val[] 배열과 weight[] 배열을 생성합니다. size 변수는 사용 가능한 패킷 수를 나타냅니다.
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
    int min_cost[100][100]; // 최대 크기로 선언

    // 0번째 행을 무한대로 채웁니다.
    for (int i = 0; i <= W; i++)
        min_cost[0][i] = INF;

    // 0번째 열을 0으로 채웁니다.
    for (int i = 1; i <= n; i++)
        min_cost[i][0] = 0;

    // 이제 각 무게에 대해 하나씩 확인하고 조건에 따라 행렬을 채웁니다.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            // weight[i-1]>j는 가방의 용량이 아이템의 무게보다 작음을 의미합니다.
            if (weight[i - 1] > j)
                min_cost[i][j] = min_cost[i - 1][j];
            // 여기서 우리는 아이템을 포함하거나 포함하지 않는 것 중에서 최소 비용을 얻습니다.
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

    // 정확한 무게 W를 주어진 무게로 만들 수 없는 경우
    if(min_cost[n][W] == INT_MAX) {
        return -1;
    }
    else {
         return min_cost[n][W];
    }

}

// 테스트 케이스를 실행하는 드라이버 프로그램
int main() {
    int cost[] = { 10,20,5,20,50 };
    int W = 30;
    int n = sizeof(cost) / sizeof(cost[0]);

    int result = MinimumCost(cost, n, W);
    printf("%d\n", result);

    return 0;
}
