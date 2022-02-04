#include <bits/stdc++.h>

using namespace std;
// 判断是否是丑数， 2，3，5的倍数
// 把2， 3， 5因数全部去了

class Solution {
public:
    bool isUgly(int n) {
        if(n < 1) return false;
        while(n%2==0)
        {
            n /= 2;
        }
        while(n%3==0)
        {
            n /= 3;

        }
        while(n%5==0)
        {
            n /= 5;

        }
        return n == 1;
    }
};