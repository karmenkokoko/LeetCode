#include <iostream>
#include <vector>
#include <unordered_map>
// 两数之和

using namespace std;

class Solution{

    public:
        vector<int> two_num(vector<int> nums, int target)
        {
            unordered_map<int, int> hashmap;
            // 哈希表存储 nums[i]和index
            for(int i = 0; i < nums.size(); i++)
            {
                unordered_map<int, int>::iterator index = hashmap.find(target-nums[i]);
                if(index != hashmap.end())
                {
                    return {index->second, i};
                }
                hashmap[nums[i]] = i;
            }
            return {};
        }
};