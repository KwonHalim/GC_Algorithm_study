#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int num = 0;
	int result[1000] = { 0 };
	scanf("%d", &num);
	for (int k = 0; k < num; k++) {
		int dp[100][100] = { 0 };
		char s[10000];
		char t[100];
		scanf("%s", t);
		scanf("%s", s);
		for (int i = 0; i <= strlen(t); i++) {
			dp[0][i] = 1;
		}
		for (int i = 1; i <= strlen(s); i++) {
			for (int j = 1; j <= strlen(t); j++) {
				if (s[i - 1] == t[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
		result[k] = dp[strlen(s)][strlen(t)];
	}
	printf("OUTPUT\n");
	for (int i = 0; i < num; i++) {
		printf("%d\n", result[i]);
	}
}