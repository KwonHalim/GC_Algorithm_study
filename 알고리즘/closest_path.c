#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct Point {
	int x, y;
}Point;


int comapreX(void* a, void* b) {
	Point* PointA = (Point*)a;
	Point* PointB = (Point*)b;
	return PointA->x - PointB->x;
}

int comapreY(void* a, void* b) {
	Point* PointA = (Point*)a;
	Point* PointB = (Point*)b;
	return PointA->y - PointB->y;
}

float dist(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

float find_min(Point p[], int n) {
	int min = 1234567890;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (dist(p[i], p[j]) < min) {
				min = dist(p[i], p[j]);
			}
		}
	}
	return min;
}

float closest(Point p[], int num) {
	if (num <= 3) {
		find_min(p, num);
	}
	int mid = num / 2;
	Point midpoint = p[mid];
	int ld = closest(p, mid);
	int rd = closest(p + mid, num - mid);
	float distance = min(ld, rd);
	Point strip[100];
	int j = 0;
	for (int i = 0; i < num; i++) {
		if (abs(p[i].x - midpoint.x) < distance) {
			strip[j] = p[i];
			j++;
		}
	}
}

