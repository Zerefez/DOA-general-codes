#pragma once
class Point {
private:
	float x, y;

public:
	Point();
	~Point();
	float distance(Point a);
};