#include <bits/stdc++.h>

using namespace std;

// 剑指 Offer 45. 把数组排成最小的数
// 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> str;
        for (int i = 0; i < nums.size(); i++)
        {
            str.push_back(to_string(nums[i]));
        }

        string res;
        quicksort(str, 0, nums.size()-1);
        for (int i = 0; i < str.size(); i++)
        {
            res += str[i];
        }
        return res;
    }

    void quicksort(vector<string>& str, int l, int r)
    {
        if(l >= r)
            return;
        int i = l-1, j = r+1;
        string mid = str[(l + r) >> 1];
        // 如果x + y > y + x 那么x > y;
        // 这里基准选为mid str
        // 例如 3, 30
        // 330 > 303 那么3应该”大于“30, 3应该在30之后
        while (i < j)
        {
            do
                i++;
            while (str[i] + mid < mid + str[i]);
            do
                j--;
            while (str[j] + mid > mid + str[j]);
            if(i < j) swap(str[i], str[j]);
        }
        quicksort(str, l, j);
        quicksort(str, j+1, r);
    }
};