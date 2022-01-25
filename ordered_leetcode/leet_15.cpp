#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 三数之和

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int first = 0; first < n; first++)
        {
            // 处理相同数字
            if(first > 0 && nums[first] == nums[first-1]) continue;
            int target = -nums[first];
            int third = n-1;
            for(int second = first+1; second < n; second++)
            {
                if(second > first+1 && nums[second] == nums[second-1]) continue;
                while(second < third && nums[second] + nums[third] > target)
                {
                    third--;
                }
                // 必须先处理指针在一起的情况
                if(second == third) break;
                // 一定要等于target
                if(nums[second] + nums[third] == target) res.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return res;
    }
};