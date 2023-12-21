#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ElephantData {
    int num;
    int weight;
    int iq;
} eData;

eData elephant[1000];

int dp[1000];
int from[1000];

int elecompare(const eData* cmp1, const eData* cmp2) {
    if (cmp1->weight == cmp2->weight)
        return cmp1->iq - cmp2->iq;
    return cmp1->weight - cmp2->weight;
}

void dpprint(int idx) {
    if (idx == -1)
        return;
    dpprint(from[idx]);
    printf("%d\n", elephant[idx].num);
}

int main() {
    int eleidx = 0;
    int i, j, maxidx, max = -1;
    int num = 0;

    while (num != 9) {
        scanf("%d %d", &elephant[eleidx].weight, &elephant[eleidx].iq);
        elephant[eleidx].num = eleidx + 1;
        eleidx++;
        num++;
    }

    qsort(elephant, eleidx, sizeof(eData), elecompare);

    for (int i = 0; i < 9; i++) {
        printf("%d %d %d\n", elephant[i].weight, elephant[i].iq, elephant[i].num);
    }
    printf("\n");

    for (i = 0; i < eleidx; i++) {
        dp[i] = 1;
        from[i] = -1;
        for (j = 0; j < i; j++) {
            if (elephant[i].iq < elephant[j].iq && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                from[i] = j;
                if (max < dp[i]) {
                    max = dp[i];
                    maxidx = i;
                }
            }
        }
    }

    printf("Maximum length of the sequence: %d\n", max);
    printf("Elephants in the sequence:\n");
    dpprint(maxidx);
    return 0;
}

#include <stdio.h>
#include <string.h>

struct Elephant {
    int w;
    int s;
    int num;
};

int len = 0;
int maxtime = 0;
char result[1000]; // 결과 문자열을 저장할 배열

void sort(struct Elephant elephants[], int len) {
    for (int i = 0; i < len - 1; i++) {
        int min = i;
        for (int j = i + 1; j < len; j++) {
            if (elephants[j].w < elephants[min].w) {
                min = j;
            }
        }
        struct Elephant temp;
        temp = elephants[i];
        elephants[i] = elephants[min];
        elephants[min] = temp;
    }
}

void compute(struct Elephant elephants[], int len) {
    for (int i = 0; i < len - 1; i++) {
        char seq_now[1000];
        sprintf(seq_now, "%d", elephants[i].num);
        int time = 1;
        int min = elephants[i].s;
        for (int j = i + 1; j < len; j++) {
            if (min > elephants[j].s) {
                char num_str[100];
                sprintf(num_str, "%d", elephants[j].num);
                strcat(seq_now, num_str);
                min = elephants[j].s;
                time++;
            }
        }

        if (time > maxtime) {
            strcpy(result, seq_now);
            maxtime = time;
        }
    }
}

int main() {
    struct Elephant elephants[1000];
    while (1) {
        int flag;
        scanf("%d", &flag);
        if (flag == 0)
            break;
        else if (flag >= 100) {
            printf("The number of elephants cannot be more than 100\n");
            break;
        }

        for (int i = 0; i < flag; i++) {
            scanf("%d %d", &elephants[len].w, &elephants[len].s);
            elephants[len].num = len + 1;
            len++;
        }

        sort(elephants, len);
        for (int i = 0; i < 9; i++) {
            printf("%d %d %d\n", elephants[i].w, elephants[i].s, elephants[i].num);
        }
        compute(elephants, len);

        printf("%d\n%s\n", maxtime, result);

        // 초기화
        len = 0;
        maxtime = 0;
        result[0] = '\0';
    }
    return 0;
}
