
#pragma once
#include "point.h"
#include <math.h>
class PointImpl :
    public Point
{
private:
    float x, y;
public:
    PointImpl(float xp, float yp) {
        x = xp;
        y = yp;
    }
    PointImpl() {
        x = 1.0 * rand() / RAND_MAX;
        y = 1.0 * rand() / RAND_MAX;
    }
    ~PointImpl() {}
    inline float getX() { return x; }
    inline float getY() { return y; }
    float distance(Point& a) {
        float dx = x - a.getX();
        float dy = y - a.getY();
        return sqrt(dx * dx + dy * dy);
    }
};

