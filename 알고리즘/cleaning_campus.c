#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a point in the 2D plane
typedef struct Point {
    float x;
    float y;
} Point;

Point startpoint;

long ccw(Point, Point, Point);
int ccwCompare(const void*, const void*);
int comparePoints(const void* , const void* );
void sortPoints(Point* points, int);


void main() {
    int num = 0;
    scanf("%d", &num);
    Point point[101];
    Point result[100];
    for (int i = 0; i < num; i++) {
        scanf("%f %f", &point[i].x, &point[i].y);
    }
    startpoint.x = 0.0;
    startpoint.y = 0.0;

    //*x,y로 정렬 필요 없음 왜? 0,0에서 시작할꺼니까
    //가장 작은 Y, 가장 작은 X
    sortPoints(point, num);
    //먼저 첫번째 정점을 정하고 -->point[0]
    startpoint = point[0];

    //각도 기준 sort하고(points 배열 sort 완료)
    qsort(point + 1, num - 1, sizeof(Point), ccwCompare);
    //출력
    printf("print\n");
    for (int i = 0; i < num; i++) {
        printf("%.2f %.2f\n", point[i].x, point[i].y);
    }
    int idx = 5;
    int temp;
    for (int i = 1; i < num; i++) {
        while (ccw(point[i], point[i + 1], point[i + 2]) <= 0) {
            if (ccw(point[i], point[i + 1], point[i + 2]) == 0) {
                break;
            }
            idx--;
        }
        result[idx] = point[i];
        idx++;
    }
    printf("Convex Hull:\n");
    for (int i = 0; i < idx; i++) {
        printf("%.2f %.2f\n", result[i].x, result[i].y);
    }

//result[0] = startpoint;
//int hullSize = 1;

//// Iterate through sorted points to find convex hull
//for (int i = 1; i < num; i++) {
//    while (hullSize > 1 && ccw(result[hullSize - 2], result[hullSize - 1], point[i]) <= 0) {
//        hullSize--;
//    }
//    result[hullSize++] = point[i];
//}

//// Print convex hull points
//printf("Convex Hull:\n");
//for (int i = 0; i < hullSize; i++) {
//    printf("%.2f %.2f\n", result[i].x, result[i].y);
//}
}


long ccw(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

int ccwCompare(const void* a, const void* b) {
    Point* p1 = (Point*)a;
    Point* p2 = (Point*)b;

    long ccwVal = ccw(startpoint, *p1, *p2);

    if (ccwVal > 0) return -1;
    if (ccwVal < 0) return 1;
    if (ccwVal == 0) return 0;
    return 0;
}

int comparePoints(const void* a, const void* b) {
    Point* point1 = (Point*)a;
    Point* point2 = (Point*)b;

    if (point1->y < point2->y) return -1;
    if (point1->y > point2->y) return 1;
    if (point1->x < point2->x) return -1;
    if (point1->x > point2->x) return 1;
    return 0;
}

void sortPoints(Point* points, int num) {
    qsort(points, num, sizeof(Point), comparePoints);
}