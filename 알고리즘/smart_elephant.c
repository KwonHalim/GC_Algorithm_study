#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct Elephant {
	int weight;
	int iq;
	int num;
} E;

void sort(E E[], int len);
void compute(E E[], int len);


void main() {
	E E[1000];
	int num = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &E[i].weight, &E[i].iq);
		E[i].num = i + 1;
	}
	sort(E, num);
    compute(E, num);
}




void sort(E elephants[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (elephants[j].weight < elephants[min].weight) {
                min = j;
            }
        }
        struct Elephant temp;
        temp = elephants[i];
        elephants[i] = elephants[min];
        elephants[min] = temp;
    }
}
                                                                                                 

void compute(E E[], int len) {//len = 9, E배열은 정렬이 된 상태
    int result[100] = { 0 };
    int final_result[100] = { 0 };
    int max = 0;
    int final_max = 0;
    int temp = 0;
    for (int i = 0; i < len; i++) {
        int min = 123456789;
        temp = 0;
        max = 0;
        for (int j = i; j < len; j++) {
            if (min > E[j].iq) {
                min = E[j].iq;
                result[temp] = E[j].num;
                temp++;
                max++;
            }
        }
        if (max > final_max) {
            final_max = max;
            printf("========\n");
            for (int i = 0; i < final_max; i++) {
                final_result[i] = result[i];
                printf("%d", final_result[i]);
            }
            printf("\n");
        }
    }
    for (int i = 0; i < 9; i++) {
        if (final_result[i] == 0)
            break;
        printf("%d ", final_result[i]);
    }
    printf("length: %d", final_max);
} 