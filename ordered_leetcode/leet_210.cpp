// 210. 课程表 II
// 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

// 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
// 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    // 静态成员变量
    static const int N = 100010;
public:
    int h[N], e[N], ne[N];
    int q[N], indegree[N];
    int idx = 0;

    // idx可能超越numCourses的大小
    void add(int a, int b)
    {
        e[idx] = b;
        ne[idx] = h[a];
        h[a] = idx;
        idx++;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        memset(h, -1, sizeof h);
        for(int i = 0 ; i < prerequisites.size(); i++)
        {
            add(prerequisites[i][1], prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        vector<int> res;
        if (topsort(numCourses))
        {
            for (int i = 0; i < numCourses; i++)
            {
                res.push_back(q[i]);
            }
            return res;
        }
        else
            return res;
    }

    bool topsort(int numCourses)
    {
        int hh = 0, tt = -1;
        for(int i = 0; i < numCourses; i++)
        {
            if(!indegree[i]) q[++tt] = i;
        }

        while(hh <= tt)
        {
            int t = q[hh++];
            for(int i = h[t]; i != -1; i = ne[i])
            {
                int j = e[i];
                indegree[j]--;
                if(!indegree[j]) q[++tt] = j;
            }
        }
        return tt == numCourses-1;

    }
};