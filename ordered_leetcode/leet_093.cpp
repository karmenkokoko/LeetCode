#include <bits/stdc++.h>

using namespace std;

// 分割ip地址
// dfs回溯算法

class Solution{
public:
    vector<string> res;

    vector<string> restoreIpAddresses(string s)
    {
        if(s.size() > 12)
            return res;
        dfs(s, 0, 0);
        return res;
    }
    // 加一个逗号的计数器
    void dfs(string& s, int index, int count)
    {
        if(count == 3)
        {
            if(isValid(s, index, s.size()-1))
            {
                res.push_back(s);
            }
            return;
        }

        for (int i = index; i < s.size(); i++)
        {
            if(isValid(s, index, i))
            {
                s.insert(s.begin() + i + 1, '.');
                count++;
                dfs(s, i+2, count);
                count--;
                s.erase(s.begin() + i + 1);
            }
            else{
                break;
            }
        }
    }
    // 判断是否是合法的数字
    bool isValid(const string& s, int start, int end)
    {
        if(start > end)
            return false;
        string num = s.substr(start, end - start + 1);
        if(num[0] == '0' && num.size() > 1)
            return false;
        int ans = 0;
        for (int i = 0; i < num.size(); i++)
        {
            ans = ans * 10 + (num[i] - '0');
        }
        if(ans > 255 || ans < 0)
            return false;
        else{
            return true;
        }
    }
};