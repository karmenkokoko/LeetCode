#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        int FindRepeatNumber(vector<int>& nums){
            int i=0;
            while(i < nums.size()){
                if(nums[i]==i){
                    i++;
                    continue;
                }
                if(nums[nums[i]] == nums[i]) return nums[i];
                swap(nums[nums[i]], nums[i]);
            }
            return -1;
        }

        Solution(){};
};

int main(int argv, char** argc){
    Solution s = Solution();
    vector<int> nums = {2, 4, 5, 6, 2, 9, 0};
    cout<<s.FindRepeatNumber(nums)<<endl;
    return 0;
}