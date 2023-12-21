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
    return -1; // 도시를 찾지 못한 경우 -1 반환
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

        int pretime = 0; // 이전 시간 초기화
        int freP = -1, nowP = -1; // 이전 도시와 현재 도시의 인덱스 초기화
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

            // 이 시점에서 이전 도시, 현재 도시, 이전 시간, 현재 시간을 사용하여 연결 여부를 확인할 수 있음

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
