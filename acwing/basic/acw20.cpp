#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int, int>> a;

// 区间合并
// 和贪心的算法很像


int main()
{
    cin >> n;
    while(n--)
    {
        int l, r;
        cin >> l >> r;
        a.push_back({l, r});

    }

    sort(a.begin(), a.end());
    int st = -2e9, ed = -2e9;
    vector<pair<int, int>> res;


    for (auto seg:a)
    {
        if(ed < seg.first)
        {
            if(st == -2e9)
            {
                // 第一个
                st = seg.first;
                ed = seg.second;
                res.push_back({st, ed});
            }
            else{
                // 先把前面的存起来
                res.push_back({st, ed});
                st = seg.first;
                ed = seg.second;
            }
        }
        else{
            ed = max(ed, seg.second);
        }
    }

    cout << res.size() << endl;

    return 0;
}