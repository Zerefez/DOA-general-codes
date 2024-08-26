
#pragma once

class Point
{
    /*Represents a point in a
        two dimentional plane*/
public:
    /*calculates the distance
      from this point to a */
    virtual float distance(Point& a) = 0;
    virtual float getX() = 0;
    virtual float getY() = 0;
};
