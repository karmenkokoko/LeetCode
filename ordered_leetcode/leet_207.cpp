#include <bits/stdc++.h>

// 207. 课程表
// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

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

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        memset(h, -1, sizeof h);
        for(int i = 0 ; i < prerequisites.size(); i++)
        {
            add(prerequisites[i][1], prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        if(topsort(numCourses)) return true;
        else return false;
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