#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int find_min(int, int, int);

void main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[100][100] = { 0 };
	int dp[100][100] = { 0 };
	int left_up = -1, left = -1, left_down = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("입력된 배열\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (j == 0) {
				dp[i][j] = arr[i][j];
				continue;
			}
			if (j > 0) {
				if (i - 1 < 0) {
					left_up = dp[n - 1][j - 1];
				}
				else {
					left_up = dp[i - 1][j - 1];
				}
				if (i + 1 >= n) {
					left_down = dp[0][j - 1];
				}
				else {
					left_down = dp[i + 1][j - 1];
				}
				left = dp[i][j - 1];
				printf("min값으로 들어가는 값:%d %d %d\n", left_up, left, left_down);
				printf("더하는 값:%d(arr배열) + %d(min값)\n", arr[i][j], find_min(left_up, left_down, left));
				dp[i][j] = arr[i][j] + find_min(left_up, left_down, left);
				printf("DP 배열\n");
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						printf("%d\t", dp[i][j]);
					}
					printf("\n");
				}
			}
		}
	}
}

int find_min(int a, int b, int c) {
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}