#include <bits/stdc++.h>

using namespace std;

// 剑指 Offer 40. 最小的k个数
// 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。


class Solution {
public:
    // 大根堆维持k个size
    
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, less<int>> big_heap;
        for(int c : arr)
        {
            big_heap.push(c);
            if(big_heap.size() > k)
            {
                big_heap.pop();
            }
            
        }
        vector<int> res;
        while(big_heap.size())
        {
            int temp = big_heap.top();
            big_heap.pop();
            res.push_back(temp);
        }

        return res;
    }
};