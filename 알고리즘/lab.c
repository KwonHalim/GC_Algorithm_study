#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

typedef struct Point {
	float x, y;
}Point;

Point startpoint = { 1111111,1111111 };
Point zero = { 0,0 };
Point v[100];
Point convex_hull[100];
int hullsize;


float ccw(Point a, Point b, Point c) {
	return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}

float dist(Point a, Point b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int compare(const void* a, const void* b) {
	Point* pointA = (Point*)a;
	Point* pointB = (Point*)b;
	if (ccw(startpoint, *pointA, *pointB) != 0)
		return ccw(startpoint, *pointA, *pointB) > 0 ? -1 : 1;
	else {
		float distA = dist(startpoint, *pointA);
		float distB = dist(startpoint, *pointB);
		return distA - distB;
	}
}



void graham(int num) {
	startpoint = v[0];
	int startpoint_index = 0;
	for (int i = 0; i < num; i++) {
		if ((v[i].y < startpoint.y) || ((startpoint.y == v[i].y) && (startpoint.x > v[i].x))) {
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


void jarvis_march(int num) {
	startpoint = v[0];
	int startpoint_index = 0;
	for (int i = 0; i < num; i++) {
		if ((startpoint.y > v[i].y) || ((startpoint.y == v[i].y) && startpoint.x > v[i].x)) {
			startpoint = v[i];
			startpoint_index = i;
		}
	}
	int current = startpoint_index;
	int next;
	do {
		convex_hull[hullsize++] = v[current];
		next = (current + 1) % num;
		for (int i = 0; i < num; i++) {
			if ((ccw(v[current], v[i], v[next]) < 0) || ((ccw(v[current], v[i], v[next]) == 0) && dist(v[current], v[i]) > dist(v[current], v[next])))
				next = i;
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
	jarvis_march(num);

	for (int i = 0; i < hullsize; i++) {
		printf("%f %f\n", convex_hull[i].x, convex_hull[i].y);
	}

	float total_length = 0;
	for (int i = 0; i < hullsize; i++) {
		total_length += dist(convex_hull[i], convex_hull[(i + 1) % hullsize]);
	}
	printf("%.2f", total_length + dist(zero, v[0]) * 2);
}