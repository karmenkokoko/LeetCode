#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n, m;
typedef pair<int, int> PII;
vector<PII> add;
vector<PII> query;
vector<int> all; // 存储所有的节点查询
int a[3 * N], s[3*N];

// 区间和
// 去重算法
vector<int>::iterator unique(vector<int>& a)
{
    int j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(!i || a[i] != a[i-1])
        {
            a[j++] = a[i];
        }
    }
    return a.begin() + j;
}

int find(int x)
{
    int l = 0, r = all.size() - 1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(all[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    // 为什么返回l+1, 因为要用到前缀和， 这样+1可以有i-1的出现
    return l+1;
}

int main()
{
    cin >> n >> m;
    while(n--)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        all.push_back(x);
    }

    while(m--)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        all.push_back(l);
        all.push_back(r);
    }

    sort(all.begin(), all.end());
    all.erase(unique(all), all.end());
    // 为什么去重，因为离散化的本质是一种映射

    for(auto item:add)
    {
        // 找到x 在查询中的位置
        int x = find(item.first);
        a[x] += item.second;
    }

    for (int i = 1; i <= all.size(); i++)
        s[i] = s[i - 1] + a[i];
    
    for(auto q:query)
    {
        int l = find(q.first), r = find(q.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}