#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        vector<int> exchange(vector<int>& nums)
        {
            int i = 0, j = nums.size()-1;
            // while
            // do while的开始index有不同
            // do while不好处理空串
            
            while(i < j)
            {
                while(i < j && (nums[i] & 1) == 1) i++;
                while(i < j && (nums[j] & 1) == 0) j--;
                swap(nums[i], nums[j]);
            }
            return nums;
        }
};
