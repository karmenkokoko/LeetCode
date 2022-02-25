#include <bits/stdc++.h>

using namespace std;

// 快速幂

// x, x^2, x^4, x^8;
// 对指数做位运算
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return x;
        double res = 1;
        long p = n;
        if(p<0)
        {
            x = 1/x;
            p = -p;
        }

        while(p)
        {
            if(p & 1) res *= x;
            x *= x;
            p >>= 1;
        }

        return res;
    }
};
