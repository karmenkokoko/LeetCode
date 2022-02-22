#include <bits/stdc++.h>

using namespace std;
// 剑指 Offer 05. 替换空格
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。


class Solution {
public:
    string replaceSpace(string s) {
        // 统计空格的数量
        int len = s.size();
        int count = 0;
        for(auto c:s)
        {
            if(c == ' ')
                count++;
        }

        // 调整s的大小
        s.resize(len + 2 * count);

        for (int i = len - 1, j = len + 2 * count - 1; i >= 0; i--, j--)
        {
            if(s[i] != ' ')
            {
                s[j] = s[i];
            }
            else{
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};