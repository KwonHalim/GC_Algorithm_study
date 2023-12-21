#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    float input[1000][3] = { 0 };
    float var[1000] = { 0 };
    int num = 0, temp = -1;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%f %f", &input[i][0], &input[i][1]);
        input[i][2] = i + 1;
    }

    // Selection sort based on 'var'
    for (int i = 0; i < num - 1; i++) {
        int min = i;
        for (int j = i + 1; j < num; j++) {
            if (var[j] < var[min])
                min = j;
        }
        // Swap 'var' values
        float tempVar = var[i];
        var[i] = var[min];
        var[min] = tempVar;

        // Swap 'input[i][2]' values
        temp = input[i][2];
        input[i][2] = input[min][2];
        input[min][2] = temp;

        for (int l = 0; l < num; l++) {
            printf("%f", var[l]);
        }
        printf("\n");
        for (int l = 0; l < num; l++) {
            printf("%f", input[l][2]);
        }
        printf("\n");
    }

    // Output in the desired format
    for (int i = num - 1; i >= 0; i--) {
        printf("%.0lf", input[i][2]);
    }

    return 0;
}
