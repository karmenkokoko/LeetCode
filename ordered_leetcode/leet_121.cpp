#include <bits/stdc++.h>

using namespace std;
// 121. 买卖股票的最佳时机
// 给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

// 你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

// 返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> left(n, INT_MAX), right(n, INT_MIN);
        left[0] = prices[0];
        right[n-1] = prices[n-1];
        for(int i = 1; i < n; i++)
        {
            left[i] = min(left[i-1], prices[i]);
        }
        for(int i = n-2; i >= 0; i--)
        {
            right[i] = max(right[i+1], prices[i]);
        }

        int max_bonus = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            max_bonus = max(max_bonus, right[i] - left[i]);
        }

        return max_bonus;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        // 一遍遍历
        // 记录最小值和最大利润
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};
