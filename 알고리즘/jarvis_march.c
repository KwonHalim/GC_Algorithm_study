#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct Point {
    int x, y;
} Point;

int orientation(Point a, Point b, Point c) {
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (val == 0) return 0;  // 일직선
    return (val > 0) ? 1 : 2;  // 반시계 방향 또는 시계 방향
}

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void convexHull(Point S[], int n) {
    if (n < 3) {
        printf("점의 개수가 3개 미만으로 볼록 껍질을 생성할 수 없습니다.\n");
        return;
    }

    Point hull[MAX_POINTS];
    int hullSize = 0;

    // 가장 멀리에 있는 점을 초기 포인트로 설정
    int startPoint = 0;
    double maxDistance = 0.0;
    for (int i = 1; i < n; i++) {
        double currentDistance = distance(S[0], S[i]);
        if (currentDistance > maxDistance) {
            maxDistance = currentDistance;
            startPoint = i;
        }
    }

    int current = startPoint;
    int next;

    double totalLength = 0.0;

    do {
        hull[hullSize++] = S[current];
        next = (current + 1) % n;
        for (int i = 0; i < n; i++) {
            if (orientation(S[current], S[i], S[next]) == 2 ||
                (orientation(S[current], S[i], S[next]) == 0 && distance(S[current], S[i]) > distance(S[current], S[next]))) {
                next = i;
            }
        }
        totalLength += distance(S[current], S[next]);
        current = next;
    } while (current != startPoint);

    // 결과 출력
    printf("Jarvis March 결과:\n");
    for (int i = 0; i < hullSize; i++) {
        printf("(%d, %d)\n", hull[i].x, hull[i].y);
    }

    printf("Convex Hull의 총 길이: %lf\n", totalLength);
}

int main() {
    int num;
    printf("점의 개수를 입력하세요: ");
    scanf("%d", &num);

    Point S[MAX_POINTS];

    for (int i = 0; i < num; i++) {
        printf("점 %d의 x, y 좌표를 입력하세요: ", i + 1);
        scanf("%d %d", &S[i].x, &S[i].y);
    }

    convexHull(S, num);

    return 0;
}
