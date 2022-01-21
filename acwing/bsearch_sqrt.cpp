#include <iostream>

using namespace std;

double n;

int main()
{
    cin >> n;
    double l = -100.0, r = 100.0;
    
    while(r - l >= 1e-8)
    {
        double mid = (l + r) / 2.0;
        if(mid * mid * mid > n) r = mid;
        else l = mid;
    }
    printf("%.6lf", l);
    return 0;
}