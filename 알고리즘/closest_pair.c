#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>


typedef struct Point
{
    int x, y;
} Point;

int compareX(const void* a, const void* b)
{
    Point* p1 = (Point*)a, * p2 = (Point*)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point* p1 = (Point*)a, * p2 = (Point*)b;
    return (p1->y - p2->y);
}

float dist(Point p1, Point p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(Point P[], int n)
{
    float min = 123456789;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

float Min(float x, float y)
{
    return (x < y) ? x : y;
}

float stripClosest(Point strip[], int size, float d)
{
    float min = d;
    qsort(strip, size, sizeof(Point), compareY);
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (dist(strip[i], strip[j]) < min)
                min = dist(strip[i], strip[j]);
    return min;
}

float closestUtil(Point P[], int n){
    if (n <= 3)
        return bruteForce(P, n);
    int mid = n / 2;
    Point midPoint = P[mid];
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);
    float d = Min(dl, dr);
    Point strip[100];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;
    return Min(d, stripClosest(strip, j, d));
}

float closest(Point P[], int n)
{
    qsort(P, n, sizeof(Point), compareX);

    return closestUtil(P, n);
}

int main(void)
{
    Point P[] = { {0, 2}, {6, 67}, {39, 107}, {43, 71}, {189,140} };
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f ", closest(P, n));
    return 0;
}