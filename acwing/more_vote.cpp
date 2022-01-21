#include <iostream>
#include <iostream>
#include <vector>

using namespace std;
// 摩尔计数
// 推论票数和 > 0
// 前a个票数和为0时，后b个票数和>0;
class Solution{
    public:
        int majorityElement(vector<int>& nums)
        {
            int x = 0, votes = 0, count = 0;
            for(int num:nums)
            {
                if(votes == 0)
                {
                    x = num;
                }
                votes += num == x ? 1:-1;

            }
            for(int num : nums)
            {
                if(num == x) count++;

            }
            return count > nums.size()/2 ? x : 0;
        }
};