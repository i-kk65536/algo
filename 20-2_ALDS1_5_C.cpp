#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Point
{
private:

public:
    double x;
    double y;

    Point(double x = 0., double y = 0.) : x(x), y(y) {}
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

Point Triangle(const Point& left, const Point& right)
{
    return Point(left + (right - left) / 2, )
}

vector<Point> KochCurve(const Point& left, const Point& right, int& depth)
{
    vector<Point> coordinate;
    coordinate.emplace_back(left);
    coordinate.emplace_back(right);
    if (depth == 0)
        return coordinate;

    auto [s, t] = Trisection(left, right);
    Point u = Triangle(s, t);
}

int main()
{
    int depth;
    cin >> depth;

    vector<Point> coordinate = KochCurve(Point(0, 0), Point(100, 0), depth);

    for (const Point& e: coordinate)
        cout << e.x << e.y << endl; 
}
