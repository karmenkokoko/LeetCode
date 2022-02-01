#include <bits/stdc++.h>

using namespace std;

// 组合总和4
// dfs 回溯可能会超时
// 不同的排列也算一种方法
// 可以取多次

// dp加回溯算法


class Solution{
    unordered_map<int, int> map;
    // 用哈希表来存之前已经有过的排列次数，这样就不用继续递归查找了，可以减少递归的次数
    int combinationSum3(vector<int> &nums, int target)
    {
        return dfs(nums, target);
    }

    int dfs(vector<int>& nums, int target)
    {
        if(target == 0)
        {
            return 1;
        }

        // 如果存在这个target的值， 直接返回
        if(map.count(target))
        {
            return map[target];
        }
        int res = 0;
        // index从0开始遍历，递归
        for (int i = 0; i < nums.size(); i++)
        {
            if(target >= nums[i])
            {
                res += dfs(nums, target - nums[i]);
            }
        }
        map.insert({target, res});
        return res;
    }
};