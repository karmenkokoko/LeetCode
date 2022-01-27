#include <bits/stdc++.h>
// 编辑距离改版
// 在自然语言处理的过程中，经常需要判断一个字符串和另外一个字符串之间的一个相似程度，其中常见的一个指标就是编辑距离，即一个字符串最少经过多少次“增删改”某个字符，可以变为另一个字符串。

// 如“abc”与“ac”的编辑距离为1，是因为在a和c中间“增加”一个b即可。如“abcd”与“axc”的编辑距离为2，是因为把“abcd”的b修改为x，然后再删除d即可，共2次操作。

// 但是在某种场景中，编辑距离定义为词粒度的。比如句子A “I am a coder”与句子B “hello ,  I am a singer”之间，对于句子A可以通过添加"hello"和符号",",  并替换"coder"为"singer"，共3个操作得到句子B。所以可得其基本的编辑距离为3。

// 在本题中，特别地，对于部分词，比如标点符号“, ”、"hello"对于句子语义的影响并不重要，这部分称之为停用词，这部分可以在匹配的过程中被跳过。比如对于句子A “I am a coder”与句子B “hello ,  I am a singer”，如果加入了停用词的影响，那编辑距离从3降到1。

// 所以目标是可以有选择性地跳过停用词的情况下，问最小的编辑距离是多少。

// 输入描述:
// 共3行
// 第一行为停用词列表，用空格区分
// 第二行为句子A，所有词可以用空格区分，词数不超过10000
// 第三行为句子B，所有词可以用空格区分，词数不超过10000

using namespace std;
 
set<string> stopmap;
 
set<string> get_stop_map(string s)
{
    set<string> ans;
    stringstream str(s);
    string stop_word;
    while(str >> stop_word) ans.insert(stop_word);
    return ans;
}
vector<string> get_string(string s)
{
    vector<string> ans;
    // ans.push_back(" ");
    stringstream str(s);
    string sss;
    while(str >> sss)
    {
        if(stopmap.count(sss) > 0)
            continue;
        ans.push_back(sss);
    }
    return ans;
}
vector<string> A;
vector<string> B;
 
int main()
{
    string str;
    getline(cin, str);
    stopmap = get_stop_map(str);
    getline(cin, str);
    A = get_string(str);
    getline(cin, str);
    B = get_string(str);
    int m = A.size();
    int n = B.size();
    int f[m+1][n+1];
    // printf("Asize, Bsize %d %d \n", m, n);
 
    memset(f, INT_MAX, sizeof f);
    for(int i = 0; i <= m; i++)
    {
        f[i][0] = i;
    }
    for(int j = 0; j <= n; j++)
    {
        f[0][j] = j;
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            f[i][j] = min(f[i-1][j]+1, f[i][j-1]+1);
            if(A[i-1] == B[j-1]) f[i][j] = min(f[i][j], f[i-1][j-1]);
            else f[i][j] = min(f[i][j], f[i-1][j-1]+1);
            // printf("i: %d, j: %d, f[i][j]: %d \n", i, j, f[i][j]);
        }
    }
    cout << f[m][n] << endl;
    return 0;
     
}