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
            // 如果说这个组最小的右端点比左端点大，那么说明是这个组的， 也就是说必须要加一个会议室
            if(!heap.size() || heap.top() > intervals[i][0])
                heap.push(intervals[i][1]);
            else{
            // 如果说最小的右端点比进来的左端点小，那么这个会议室可以给进来的那个用， 但这个会议室的结束时间改成新来的结束时间
                heap.pop();
                res--;
                heap.push(intervals[i][1]);
            }
        }
        return res;
    }
};