#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct Point {
	float x, y;
}Point;

Point startpoint;
Point v[100];
Point convex_hull[100];
Point zero = { 0,0 };
int hullsize = 0;

float ccw(Point a, Point b, Point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

float dist(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int compare(const void* a, const void* b) {
	Point* pointA = (Point*)a;
	Point* pointB = (Point*)b;
	if (ccw(startpoint, *pointA, *pointB) != 0) {
		return ccw(startpoint, *pointA, *pointB) > 0 ? -1 : 1;
	}
	else {
		return dist(startpoint, *pointA) - dist(startpoint, *pointB);
	}
}


void graham(int num) {
	int startpoint_index = 0;
	startpoint = v[0];
	for (int i = 0; i < num; i++) {
		if ((startpoint.y > v[i].y) || ((startpoint.y == v[i].y) && (startpoint.x > v[i].x))) {
			startpoint = v[i];
			startpoint_index = i;
		}
	}
	v[startpoint_index] = v[0];
	v[0] = startpoint;

	qsort(&v[1], num - 1, sizeof(Point), compare);

	convex_hull[0] = v[0];
	convex_hull[1] = v[1];
	hullsize = 2;

	for (int i = 0; i < num; i++) {
		while (hullsize >= 2) {
			if (ccw(convex_hull[hullsize - 2], convex_hull[hullsize - 1], v[i]) > 0)
				break;
			hullsize--;
		}
		convex_hull[hullsize] = v[i];
		hullsize++;
	}
}


void jarvis(int num) {
	int startpoint_index = 0;
	for (int i = 0; i < num; i++) {
		if ((v[i].y < v[startpoint_index].y) || ((v[startpoint_index].y == v[i].y) && (v[startpoint_index].x > v[i].x))) {
			startpoint_index = i;
		}
	}
	startpoint = v[startpoint_index];
	int current = startpoint_index;
	int next; 

	do { 
		convex_hull[hullsize++] = v[current];
		next = (current + 1) % num;
		for (int i = 0; i < num; i++) {
			if (ccw(v[current], v[i], v[next]) > 0 || ((ccw(v[current], v[i], v[next]) == 0) && (dist(v[current], v[i]) > dist(v[current], v[next])))) {
				next = i;
			}
		}
		current = next;
	} while (current != startpoint_index);

}

	
void main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%f %f", &v[i].x, &v[i].y);
	}

	//graham(num);
	jarvis(num);
	float result = 0;
	for (int i = 0; i < hullsize; i++) {
		result += dist(convex_hull[i], convex_hull[(i + 1) % hullsize]);
	}
	printf("%.2f", result + dist(zero, startpoint) * 2);
}