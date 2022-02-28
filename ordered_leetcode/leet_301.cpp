#include <bits/stdc++.h>

using namespace std;
// 301. 删除无效的括号
// 给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。

// 返回所有可能的结果。答案可以按 任意顺序 返回。


class Solution {
public:
    unordered_set<string> st;
    vector<string> removeInvalidParentheses(string s) {
        // l, r表示还剩几个需要删除
        int l = 0, r = 0;

        // 统计s中括号的数量， 需要删除的数量
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                l++;
            }
            else if(s[i] == ')')
            {
                if(!l)
                {
                    // 要删除的左括号为0, 那么这个右括号一定得删
                    r++;
                }
                else{
                    // 找到配对，
                    l--;
                }
            }
        }

        string t = "";
        dfs(s, t, l, r, 0, 0, 0);

        vector<string> res;
        for(auto s : st)
        {
            res.push_back(s);
        }
        return res;
    }

    void dfs(string& s, string& t, int l, int r, int begin, int cntl, int cntr)
    {
        if(begin == s.size())
        {
            if(l == 0 && r == 0)
                st.insert(t);
            return;
        }

        if(s[begin] == '(' && l > 0)
        {
            // 如果有冗余括号，那么跳过这个左括号， 搜索下面的
            dfs(s, t, l - 1, r, begin + 1, cntl, cntr);
        }

        if(s[begin] == ')' && r > 0)
        {
            dfs(s, t, l, r - 1, begin + 1, cntl, cntr);
        }

        t.push_back(s[begin]);

        if(s[begin] != '(' && s[begin] != ')')
        {
            dfs(s, t, l, r, begin + 1, cntl, cntr);
        }
        else if(s[begin] == '(')
        {
            dfs(s, t, l, r, begin + 1, cntl + 1, cntr);
        }
        else if(s[begin] == ')' && cntl > cntr)
        {
            // 最后要确保l的次数大于r
            dfs(s, t, l, r, begin + 1, cntl, cntr+1);
        }
    }
};