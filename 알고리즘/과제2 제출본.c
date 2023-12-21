#define time 30
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//find_max: find biggest number in the array and return the number
int find_max(int arr[], int len) {
    int max = arr[0];
    for (int i = 1; i < len; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int num[time] = { 0 };
    int result[100] = { 0 };
    int number = 0;
    while (1) {
    printf("number of pancakes: ");
    scanf("%d", &number);//number of pancakes
    if (number > 30 || number < 1) {
        printf("pancake should be more than 1, less than 30\n");
    }
    else
        break;
    }
    for (int i = 0; i < number; i++) {
        scanf("%d", &num[i]);
        if (num[i] > 10 || num[i] < 1) {
            printf("diameter should be between 1 ~ 10, turn off the program");
            return 0;
        }
    }

    int temp = number;
    int j = 0;

    while (temp != 0) {
        int big = find_max(num, temp);
        int cnt = 0;
        //find the index number of the biggest pancake
        while (num[cnt] != big) {
            cnt++;
        }
        //move the biggest pancake to top
        for (int i = 0; i < (cnt + 1) / 2; i++) {
            swap(&num[i], &num[cnt - i]);
        }
        //move the biggest pancake to the bottom.
        for (int i = 0; i < temp / 2; i++) {
            swap(&num[i], &num[temp - 1 - i]);
        }
        //store filp number
        if (temp != (cnt + 1)) {
            result[j] = cnt + 1;
            result[j + 1] = temp;
            j = j + 2;
        }
        temp--;
    }
    printf("(");
    for (int i = 0; i < number; i++) {
        printf("%d ", num[i]);
    }
    printf(")");
    printf("\n");
    int k = 0;
    for (int k = 0; result[k] != 0; k += 1) { //0 means nothing, so continue
        if (result[k] == 1) {
            continue;
        }
        printf("%d ", number + 1 - result[k]);
    }
    printf("0");
}
