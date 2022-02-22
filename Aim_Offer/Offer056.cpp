// 剑指 Offer 56 - I. 数组中数字出现的次数
// 一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 用div做分割，将数组分割成两个，div算一个标记, 每一个数组做异或
        int res = 0, div = 1;
        for(int num:nums)
        {
            res ^= num;
        }

        while((res & div) == 0)
        {
            div <<= 1;
        }
        int a = 0, b = 0;
        for (int num : nums)
        {
            if(num&div)
                a ^= num;
            else
                b ^= num;
        }

        return vector<int> {a, b};
    }
};