// 253. 会议室 II
// 给你一个会议时间安排的数组 intervals ，
// 每个会议时间都会包括开始和结束的时间 intervals[i] = [starti, endi] ，返回 所需会议室的最小数量 。
#include <bits/stdc++.h>

using namespace std;

// 区间分组
class Solution
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int res = n;

        priority_queue<int, vector<int>, greater<int>> heap;
        // 维护小根堆, 存右节点
        for (int i = 0; i < n; i++)
        {
            if(!heap.size() || heap.top() > intervals[i][0])
                heap.push(intervals[i][1]);
            else{
                heap.pop();
                res--;
                heap.push(intervals[i][1]);
            }
        }
        return res;
    }
};