#include <iostream>
#include <deque>
#include <utility>
#include <cmath>
using namespace std;

class Point
{
private:

public:
    double x;
    double y;

    Point(double x=0., double y=0.) : x(x), y(y) {}
	Point Rotate(const double& angle, const Point& origin=Point())
	{
		*this -= origin;
		constexpr double PI = 3.141592653589793;
		double rad = angle * PI / 180;
		double cos = cos(rad);
		double sin = sin(rad);
		this->x = this->x * cos - this->y * sin;
		this->y = this->x * sin + this->y * cos;
		*this += origin;
		return *this;
	}
    Point operator+(const Point& other) const
    {
        return Point(x + other.x, y + other.y);
    }
    Point operator-(const Point& other) const
    {
        return Point(x - other.x, y - other.y);
    }
    Point operator*(double scalar) const
    {
        return Point(x * scalar, y * scalar);
    }
    Point operator/(double scalar) const
    {
        return Point(x / scalar, y / scalar);
    }
};

pair<Point, Point> Trisection(const Point& left, const Point& right)
{
    Point diff =  (right - left) / 3;
    return {left + diff, left + diff * 2};
}

Point CalculateTriangleTop(const Point& left, const Point& right)
{
	Point terget = right;
    return terget.Rotate(60., left);
}

deque<Point> KochCurve(const Point& left, const Point& right, int& depth)
{
    deque<Point> coordinate;
    if (depth == 0)
	{
		coordinate.emplace_front(left);
		coordinate.emplace_back(right);
        return coordinate;
	}

    auto [a, c] = Trisection(left, right);
    Point b = CalculateTriangleTop(a, c);
	depth--;

	coordinate.emplace_back(left);
	deque<Point> que1 = KochCurve(left, a);
	deque<Point> que2 = KochCurve(a, b);
	deque<Point> que3 = KochCurve(b, c);
	deque<Point> que4 = KochCurve(c, right);
	coordinate.insert(coordinate.end(), que1.begin(), que2.end());
}

int main()
{
    int depth;
    cin >> depth;

    deque<Point> coordinate = KochCurve(Point(0, 0), Point(100, 0), depth);

    for (const Point& e: coordinate)
        cout << e.x << e.y << endl; 
}
