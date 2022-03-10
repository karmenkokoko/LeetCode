#include <bits/stdc++.h>

using namespace std;

// 八数码

int bfs(string state)
{
    queue<string> q;
    unordered_map<string, int> d;
    string end = "12345678x";
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    q.push(state);
    d.insert({state, 0});
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        if(t == end)
            return d[t];
        int distance = d[t];
        int k = t.find("x");
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[3 * a + b], t[k]);
                if(!d[t])
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[3 * a + b], t[k]);
            }
        }
    }
    return -1;
}

int main()
{
    char ss[2];
    string state;
    for (int i = 0; i < 9; i++)
    {
        cin >> ss;
        state += ss;
    }
    cout << bfs(state) << endl;
    return 0;
}