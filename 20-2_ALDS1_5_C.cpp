#include <iostream>
#include <iomanip>
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

        constexpr double PI = 3.14159;
        double rad = angle * PI / 180.;
        double cos_val = cos(rad);
        double sin_val = sin(rad);
        double new_x = this->x * cos_val - this->y * sin_val;
        double new_y = this->x * sin_val + this->y * cos_val;
        this->x = new_x;
        this->y = new_y;

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
    Point operator*(const double& scalar) const
    {
        return Point(x * scalar, y * scalar);
    }
    Point operator/(const double& scalar) const
    {
        return Point(x / scalar, y / scalar);
    }
    Point operator+=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Point operator-=(const Point& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }
};

pair<Point, Point> Trisection(const Point& left, const Point& right)
{
    Point diff = (right - left) / 3;
    return {left + diff, left + diff * 2};
}

Point CalculateTriangleTop(const Point& left, const Point& right)
{
    Point terget = right;
    return terget.Rotate(60., left);
}

void HelpKochCurve(deque<Point>& coordinate, const Point& A, const Point& E, int depth)
{
    if (depth == 0)
        return;

    auto [B, D] = Trisection(A, E);
    Point C = CalculateTriangleTop(B, D);

    HelpKochCurve(coordinate, A, B, depth - 1);
    coordinate.emplace_back(B);
    HelpKochCurve(coordinate, B, C, depth - 1);
    coordinate.emplace_back(C);
    HelpKochCurve(coordinate, C, D, depth - 1);
    coordinate.emplace_back(D);
    HelpKochCurve(coordinate, D, E, depth - 1);
}

deque<Point> KochCurve(const Point& left, const Point& right, const int& depth)
{
    deque<Point> coordinate;
    
    coordinate.emplace_front(left);
    HelpKochCurve(coordinate, left, right, depth);
    coordinate.emplace_back(right);

    return coordinate;
}

int main()
{
    int depth;
    cin >> depth;

    deque<Point> coordinate = KochCurve(Point(0., 0.), Point(100., 0.), depth);

    cout << fixed << setprecision(4);
    for (const Point& e: coordinate)
        cout << e.x << " " << e.y << endl; 
}
