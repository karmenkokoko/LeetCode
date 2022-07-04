#include <bits/stdc++.h>

using namespace std;


// 接雨水
// 计算两边的最高然后加起来


class Solution{
    public:
        int take_water(vector<int> &height)
        {
            int sum;
            int n = height.size();
            vector<int> maxright(n, 0);
            vector<int> maxleft(n, 0);

            for (int i = 1; i < n; i++)
            {
                maxleft[i] = max(maxleft[i - 1], height[i - 1]);
            }
            for (int i = n - 2; i >= 0; i--)
            {
                maxright[i] = max(maxright[i + 1], height[i + 1]);
            }

            for (int i = 1; i < n - 1; i++)
            {
                int min_height = min(maxleft[i], maxright[i]);
                if(min_height > height[i])
                {
                    sum += min_height - height[i];
                }
            }

            return sum;
        }
};