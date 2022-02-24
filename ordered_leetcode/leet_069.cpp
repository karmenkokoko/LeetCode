#include <bits/stdc++.h>

using namespace std;
// 69. x 的平方根 
// 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。

// 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。

// 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        if(x == 1)
            return 1;
        // 平方根范围一定在1, x/2之间
        int left = 1;
        int right = x / 2;
        while(right > left)
        {
            int mid = (right + left + 1) / 2;
            if(mid > x / mid)
                right = mid - 1;
            else left = mid;

        }
        return left;
    }
};