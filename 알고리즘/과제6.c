#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int find_min(int, int, int);

void main() {
	int n, m;
	int temp = 0;
	int result = 1234567890;
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
	int path[100];
	int min = 123465789;
	int lu, le, ld;
	int index = -1;
	int min2 = 123456789;
	for (int i = 0; i < n; i++) {
		if (min > dp[i][m - 1]) {
			min = dp[i][m - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		if (min == dp[i][m - 1]) {
			index = i;
			printf("index : %d\n", index);
			//path[m-1] = arr[i][m-1];
			break;
		}
	}
	//왼쪽위,왼쪽아래,왼쪽 3가지 값 중에 가장 작은 값으로 인덱스 이동
	for (int j = m-1 ; j >= 0; j--) {
		if (index - 1 < 0) {
			lu = dp[n - 1][j];
		}
		else {
			lu = dp[index - 1][j];
		}
		if (index + 1 >= n) {
			ld = dp[0][j];
		}
		else {
			ld = dp[index + 1][j];
		}
		le = dp[index][j];
		min = find_min(lu, le, ld);

		for (int i = 0; i < m; i++) {
			if (min == dp[i][j]) {
				printf("index: %d\n", i);
				index = i;
				path[temp] = arr[index][j];
				temp++;
				break;
			}
		}
	}
	for (int i = m-1; i >=0; i--) {
		printf("%d ", path[i]);
	}
	for (int i = 0; i < n; i++) {
		min = dp[i][m];
		result = min(min, dp[i][m]);
	}
	printf("result:%d\n", result);
}

int find_min(int a, int b, int c) {
	int min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return min;
}