using namespace std;

#include <iostream>
#include <math.h>
#include "point_plus.h"

/* Constructor of a point. */
Point::Point() {
	x = 1.0 * rand() / RAND_MAX;
	y = 1.0 * rand() / RAND_MAX;
}

/* Destructor of a point. */
Point::~Point() {}

/* Compute the distance between points. */
float Point::distance(Point a, Point b) {
	float dx = a.X() - b.X();
	float dy = a.Y() - b.Y();
	return sqrt(dx * dx + dy * dy);
}

#define EPSILON 0.001f

int operator==(Point a, Point b) {
	return Point::distance(a, b) < EPSILON;
}

ostream& operator<<(ostream& t, Point p) {
	cout << "(" << p.x << " ," << p.y << ")";
	return t;
}
