#include <bits/stdc++.h>

using namespace std;
// 电话号码的组合
// 和组合总数一样

class Solution{
public:
    unordered_map<char, string> map{
        {'2', "abc"},
        {'3', "edf"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
    };
    vector<string> res;
    string path;
    vector<string> letterCombinations(string digits)
    {
        dfs(digits, 0);
        return res;
    }
    void dfs(string& digits, int index)
    {
        if(index == digits.size())
        {
            res.push_back(path);
            return;
        }

        char n = digits[index];
        string container = map[n];
        for(char c:container)
        {
            path.push_back(c);
            dfs(digits, index + 1);
            path.pop_back();
        }
    }
};