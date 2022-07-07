#include <bits/stdc++.h>

using namespace std;


// 比较版本号, 双指针模拟
class Solution{
    public:
        int compare_version(string version1, string version2)
        {
            int n = version1.size(), m = version2.size();
            int i = 0, j = 0;
            while(i < n || j < m)
            {
                long long x;
                for (; i < n && version1[i] != '.'; ++i)
                {
                    x = x * 10 + version1[i] - '0';
                }
                ++i;

                long long y;
                for (; j < m && version2[j] != '.'; ++j)
                {
                    y = y * 10 + version2[j] - '0';
                }
                ++j;

                if(x != y)
                {
                    return x > y ? 1 : -1;
                }
            }
            return 0;
        }
};