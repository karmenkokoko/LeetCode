#include <bits/stdc++.h>

// 3. 无重复字符的最长子串
// unordered_set 无序的set
// 键值不允许重复

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        // set其实用于计数
        // 但是给字符串计数数组是不行的

        int ans = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while(set.find(s[i]) != set.end())
            {
                set.erase(s[j]);
                j++;
            }
            ans = max(ans, i - j + 1);
            set.insert(s[i]);
        }
        return ans;
    }
};

class Solution2
{
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> set;
        // map也行
        // 但是给字符串计数数组是不行的
        
        int ans = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++)
        {
            while(j < i && set[s[i]] > 0)
            {
                set[s[j]]--;
                j++;
            }
            ans = max(ans, i - j + 1);
            set[s[i]]++;
        }
        return ans;
    }
};