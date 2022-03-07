# include <bits/stdc++.h>

using namespace std;

// 187. 重复的DNA序列
// DNA序列 由一系列核苷酸组成，缩写为 'A', 'C', 'G' 和 'T'.。

// 例如，"ACGAATTCCG" 是一个 DNA序列 。
// 在研究 DNA 时，识别 DNA 中的重复序列非常有用。

// 给定一个表示 DNA序列 的字符串 s ，返回所有在 DNA 分子中出现不止一次的 长度为 10 的序列(子字符串)。你可以按 任意顺序 返回答案。


// 用哈希表来存所有10位的序列
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> res;

        if(s.size() <= 10) return res;
        for(int i = 0; i <= s.size()-10; i++)
        {
            map[s.substr(i, 10)]++;
        }

        for(auto item:map)
        {
            if(item.second > 1)
            {
                res.push_back(item.first);
            }
        }
        return res;
    }
};