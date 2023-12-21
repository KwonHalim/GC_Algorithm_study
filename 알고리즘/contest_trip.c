#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct city {
    char name[100];
    int position;
};

struct edge {
    int start, end;
    int time;
};

int findPosition(struct city* city, char* name, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(city[i].name, name) == 0)
            return i;
    }
    return -1; // ���ø� ã�� ���� ��� -1 ��ȯ
}

int main() {
    int N;
    scanf("%d", &N);

    struct city* city;
    struct edge* edge;

    for (int i = 0; i < N; i++) {
        int size, allsize;
        scanf("%d", &size);
        city = (struct city*)malloc(sizeof(struct city) * size);

        for (int j = 0; j < size; j++) {
            scanf("%s", city[j].name);
            city[j].position = j;
        }

        scanf("%d", &allsize);
        edge = (struct edge*)malloc(sizeof(struct edge) * allsize);

        int pretime = 0; // ���� �ð� �ʱ�ȭ
        int freP = -1, nowP = -1; // ���� ���ÿ� ���� ������ �ε��� �ʱ�ȭ
        int nowtime = 0;
        for (int j = 0; j < allsize; j++) {
            int cases;
            scanf("%d", &cases);

            for (int k = 0; k < cases; k++) {
                int nt;
                char now[100];
                scanf("%d %s", &nt, now);

                pretime = nowtime;
                freP = nowP;
                nowP = findPosition(city, now, size);
                nowtime = (nt / 100) * 60 + nt % 100;
            }

            // �� �������� ���� ����, ���� ����, ���� �ð�, ���� �ð��� ����Ͽ� ���� ���θ� Ȯ���� �� ����

            if (freP != -1 && nowP != -1) {
                printf("Departure %04d %s\n", pretime, city[freP].name);
                printf("Arrival %04d %s\n", nowtime, city[nowP].name);
            }
            else {
                printf("No connection\n");
            }
        }

        free(city);
        free(edge);
    }

    return 0;
}
