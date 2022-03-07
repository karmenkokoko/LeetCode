#include <bits/stdc++.h>
using namespace std;
// 835. Trie字符串统计
// 维护一个字符串集合，支持两种操作：

// I x 向集合中插入一个字符串 x；
// Q x 询问一个字符串在集合中出现了多少次。
// 共有 N 个操作，输入的字符串总长度不超过 105，字符串仅包含小写英文字母。

// 输入格式
// 第一行包含整数 N，表示操作数。

// 接下来 N 行，每行包含一个操作指令，指令为 I x 或 Q x 中的一种。

// 输出格式
// 对于每个询问指令 Q x，都要输出一个整数作为结果，表示 x 在集合中出现的次数。

// 每个结果占一行。
const int N = 20010;
int n;
char ch[N];
int son[N][26];
int idx;
int cnt[N];

void insert(char ch[])
{
    // p 表示根的idx
    int p = 0;
    for (int i = 0; ch[i]; i++)
    {
        int u = ch[i] - 'a';
        if(!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(char ch[])
{
    int p = 0;
    for (int i = 0; ch[i]; i++)
    {
        int u = ch[i] - 'a';
        if(!son[p][u])
            return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    cin >> n;
    while(n--)
    {
        string op;
        
        cin >> op >> ch;

        if(op == "I")
        {
            insert(ch);
        }
        else{
            printf("%d\n", query(ch));
        }
    }
    return 0;
}