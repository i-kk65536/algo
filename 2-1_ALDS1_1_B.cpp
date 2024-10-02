#include<iostream>
using namespace std;

int gcd(int, int);

int main(void)
{
    int x, y;
    cin >> x >> y;

    cout << gcd(x, y) << endl;
}

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}