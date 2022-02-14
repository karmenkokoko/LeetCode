// 169. 多数元素
// 给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。

// 你可以假设数组是非空的，并且给定的数组总是存在多数元素。

#include <bits/stdc++.h>

using namespace std;
// 摩尔计数
// 推论票数和 > 0
// 前a个票数和为0时，后b个票数和>0;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x = 0, vote = 0, count = 0;
        for(int num:nums)
        {
            if(vote == 0)
            {
                x = num;
            }
            vote += num == x ? 1 : -1;
        }

        for(int num:nums)
        {
            if(num == x)
            {
                count++;
            }
        }

        return count > nums.size() / 2 ? x : 0;
    }
};