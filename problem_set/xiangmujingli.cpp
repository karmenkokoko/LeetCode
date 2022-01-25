#include <bits/stdc++.h>

using namespace std;
const int N = 10010;
vector<int> a, b;
vector<int> g[N];
bool st[N];
int match[N];

// 处理输入字符串
vector<int> get_num(string s)
{
    vector<int> a;
    // 字符串流
    stringstream str(s);
    int temp;
    while(str >> temp) a.push_back(temp);
    return a;
}

bool find(int x)
{
    for(auto v:g[x])
    {
        if(st[v]) continue;
        st[v] = true;
        if(match[v] == -1 || find(match[v]))
        {
            match[v] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    getline(cin, s);
    a = get_num(s);
    getline(cin, s);
    b = get_num(s);
    
    int n;
    cin >> n;
    while(n--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    memset(match, -1, sizeof match);
    int cnt = 0;
    for(int i = 0; i < a.size(); i++)
    {
        memset(st, 0, sizeof st);
        if(find(a[i])) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
