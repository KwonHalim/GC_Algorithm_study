#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define num 100

int calculate(int, int [], int);
int avg(int [], int);


void main() {
	int mon[num] = { 0 };
	int input = -1;
	int mon_avg = 0;
	int len = 0;
	int true = 1;
	while (true) {
		scanf("%d", &input);
		if (input == 0) {
			break;
		}
		for (int i = 0; i < input; i++) {
			scanf("%d", &mon[i]);
		}
			mon_avg = avg(mon, input);
			calculate(mon_avg, mon, input);
	}
	memset(mon, 0, sizeof(mon));
}

int calculate(int avg, int arr[], int len) {
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < len; i++) { 
		if (arr[i] - avg <= 0)
			continue;
		temp = arr[i] - avg;
		temp = temp - temp % 10;//10원 미만은 버림
		sum = sum + temp;
	}
	printf("%d\n", sum);
}

int avg(int arr[], int len) {
	int i = 0;
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum = sum + arr[i];
	}
	return sum / len;
}