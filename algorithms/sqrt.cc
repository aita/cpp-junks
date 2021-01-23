#include <iostream>
#include <iomanip>
#include <limits>
#include <cassert>

double sqrt(double a)
{
    assert(a >= 0);

    double left = 0;
    double right = a;
    double y1 = 0;
    while (true)
    {
        double x = (left + right) / 2;
        double y = x * x - a;
        if (std::abs(y - y1) <= std::numeric_limits<double>::epsilon())
        {
            return x;
        }
        if (y < 0)
        {
            left = x;
        }
        else
        {
            right = x;
        }
        y1 = y;
    }
}

int main()
{
    using namespace std;

    cout << std::setprecision(20) << sqrt(2) << endl;

    return 0;
}