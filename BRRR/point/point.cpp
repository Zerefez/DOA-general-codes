#include <math.h>
#include "point.h"
#include <stdlib.h>

/* Constructor of a point. */
Point::Point() {
	x = 1.0 * rand() / RAND_MAX;
	y = 1.0 * rand() / RAND_MAX;
}

/* Destructor of a point. */
Point::~Point() {}

/* Compute the distance to another point. */
float Point::distance(Point a) {
	float dx = x - a.x;
	float dy = y - a.y;
	return sqrt(dx * dx + dy * dy);
}