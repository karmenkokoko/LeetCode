// KMP字符串
// 给定一个模式串 S，以及一个模板串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。

// 模板串 P 在模式串 S 中多次作为子串出现。

// 求出模板串 P 在模式串 S 中所有出现的位置的起始下标。

// 输入格式
// 第一行输入整数 N，表示字符串 P 的长度。

// 第二行输入字符串 P。

// 第三行输入整数 M，表示字符串 S 的长度。

// 第四行输入字符串 S。

// 输出格式
// 共一行，输出所有出现位置的起始下标（下标从 0 开始计数），整数之间用空格隔开。

#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int n, m;
int ne[N];
char p[N], s[N];

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        int m = haystack.size();
        if(n == 0) return 0;
        vector<int> ne(n+1);
        // 可以在字符串之前加' ' 保证字符串从1开始
        haystack.insert(haystack.begin(), ' ');
        needle.insert(needle.begin(), ' ');
        
        // 双引号视作字符串，单引号视作字符
        for(int i = 2, j = 0; i <= n; i++)
        {
            while(j && needle[i] != needle[j+1]) j = ne[j];
            if(needle[i] == needle[j+1]) j++;
            ne[i] = j;
        }
        for(int i = 1, j = 0; i <= m; i++)
        {
            while(j && haystack[i] != needle[j+1]) j = ne[j];
            if(haystack[i] == needle[j+1]) j++;
            if(j == n) return i - n;
        }
        return -1;
    }
};


int main()
{
    // 
    cin >> n >> p + 1 >> m >> s + 1;

    // p从第二个字符开始 求ne数组
    for (int i = 2, j = 0; i <= n; i++)
    {
        while(j && p[i] != p[j+1])
            j = ne[j];
        if(p[i] == p[j+1])
            j++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i++)
    {
        while(j && s[i] != p[j+1])
            j = ne[j];
        if(s[i] == p[j+1])
            j++;
        if(j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }
    return 0;
}