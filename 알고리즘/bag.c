#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main()
{
    while (1)
    {
        int n = 0;
        printf("type the number of jewel: ");
        scanf("%d", &n);
        printf("\n");
        if (n == 0) break;

        int n1, c1, n2, c2;
        scanf("%d %d", &c1, &n1);
        printf("\n");
        scanf("%d %d", &c2, &n2);
        printf("\n");

        int maxN = 0;
        int max = 0;
        int tmp = 0;
        if (n1 / c1 > n2 / c2) {
            maxN = n / n1;//¸ò
            max = n1;
            tmp = n2;
        }
        else
        {
            maxN = n / n2;
            max = n2;
            tmp = n1;
        }
        int finish = 0;
        for (int j = maxN; j > 0; j--) {
            if (finish == 1) break;
            for (int i = 0; i < maxN; i++) {
                if ((j * n1) + (tmp * i) == n) {
                    if (max == n1) {
                        printf("%d %d", j, i);
                        printf("\n");
                        finish = 1;
                        break;
                    }
                }
                else if ((j * n2) + (tmp * i) == n) {
                    if (max == n1) {
                        printf("%d %d", j, i);
                        printf("\n");
                        finish = 1;
                        break;
                    }
                }
            }
        }
        if (finish == 0) printf("failed\n");
    }
}