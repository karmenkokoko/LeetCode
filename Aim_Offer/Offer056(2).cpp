#include <bits/stdc++.h>

using namespace std;
// 剑指 Offer 56 - II. 数组中数字出现的次数 II
// 在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

// 记录每一位的数字
class Solution {
public:
    typedef long long LL;
    LL singleNumber(vector<int>& nums) {
        int bit[32];
        memset(bit, 0, sizeof bit);
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < 32; j++)
            {
                if(nums[i] & 1 == 1)
                {
                    bit[j]++;
                }
                nums[i] >>= 1;
            }
        }

        LL res = 0;

        for(int i = 0; i < 32; i++)
        {
            if((bit[i] % 3) == 1)
            {
                res += pow(2, i);
            }
        }
        return res;
        
    }
};