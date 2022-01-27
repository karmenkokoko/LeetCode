#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution{
    public:
        vector<int> getLeastNumbers(vector<int>& arr, int k)
        {
            vector<int> res;
            priority_queue<int, vector<int>, less<int>> big_heap;

            for(auto c : arr)
            {
                big_heap.push(c);
                if(big_heap.size() > k)
                {
                    big_heap.pop();
                }
            }

            for(int i = 0; i < k; i++)
            {
                res.push_back(big_heap.top());
                big_heap.pop();
            }
            return res;
        }
};