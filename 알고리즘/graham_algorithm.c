#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
    int x, y;
} Point;

Point v[100];
Point hull[100];
int hullsize = 0;
Point startpoint;
Point zero = { 0, 0 };

double ccw(Point a, Point b, Point c) {
    return (double)(a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y));
}

double dist(Point a, Point b) {
    return sqrt((a.x - b.x)* (a.x - b.x) + (a.y - b.y)* (a.y - b.y));
}

int compare(const void* a, const void* b) {
    Point* pointA = (Point*)a;
    Point* pointB = (Point*)b;
    double distA;
    double distB;
    if (ccw(startpoint, *pointA, *pointB) != 0) {
        return (ccw(startpoint, *pointA, *pointB) > 0) ? -1 : 1;
    }
    else {
        distA = dist(startpoint, *pointA);
        distB = dist(startpoint, *pointB);
        return distA - distB;
    }
}

void convexHull(int num) {
    int minDist = 1234567890;
    int closestPointIndex = -1;

    for (int i = 0; i < num; i++) {
        double currentDist = dist(zero, v[i]);
        if (currentDist < minDist) {
            minDist = currentDist;
            closestPointIndex = i;
        }
    }

    startpoint = v[closestPointIndex];
    v[closestPointIndex] = v[0];
    v[0] = startpoint;

    qsort(&v[1], num - 1, sizeof(Point), compare);

    hullsize = 2;
    hull[0] = v[0];
    hull[1] = v[1];

    for (int i = 2; i < num; i++) {
        while (hullsize >= 2) {
            double rotate = ccw(hull[hullsize - 2], hull[hullsize - 1], v[i]);
            if (rotate > 0) {
                break;
            }
            hullsize--;
        }
        hull[hullsize] = v[i];
        hullsize++;
    }
}

int main() {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d %d", &v[i].x, &v[i].y);
    }

    convexHull(num);

    printf("hull_num:%d\n", hullsize);
    for (int i = 0; i < hullsize; i++) {
        printf("%d %d\n", hull[i].x, hull[i].y);
    }
    double total_len = 0;
    for (int i = 0; i < hullsize; i++) {
        total_len += dist(hull[i], hull[(i + 1)]);
    }
    printf("Total Length: %lf\n", total_len);
}
