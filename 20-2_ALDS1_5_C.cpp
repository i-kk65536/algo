#include <iostream>
#include <iomanip>
#include <deque>
#include <utility>
#include <cmath>
using namespace std;

class Point
{
private:
    double x;
    double y;

public:
    Point(double x=0., double y=0.) : x(x), y(y) {}
    Point Rotated(const double& angle, const Point& origin=Point()) const
    {
        constexpr double PI = 3.14159;
        double rad = angle * PI / 180.;
        double cos_val = cos(rad);
        double sin_val = sin(rad);

        Point translated(*this - origin);
        Point rotated(
            translated.x * cos_val - translated.y * sin_val,
            translated.x * sin_val + translated.y * cos_val
        );
        return rotated + origin;
    }
    void Print() const
    {
        cout << this->x << " " << this->y << endl;
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
    Point& operator+=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Point& operator-=(const Point& other)
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
    return right.Rotated(60., left);
}

deque<Point> KochCurve(const Point& left, const Point& right, const int& depth)
{
    deque<Point> coordinate;

    auto helper = [&coordinate](auto self, const Point& A, const Point& E, int depth) -> void {
        if (depth == 0)
            return;

        auto [B, D] = Trisection(A, E);
        Point C = CalculateTriangleTop(B, D);

        self(self, A, B, depth - 1);
        coordinate.emplace_back(B);
        self(self, B, C, depth - 1);
        coordinate.emplace_back(C);
        self(self, C, D, depth - 1);
        coordinate.emplace_back(D);
        self(self, D, E, depth - 1);
    };

    coordinate.emplace_front(left);
    helper(helper, left, right, depth);
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
        e.Print();
}
