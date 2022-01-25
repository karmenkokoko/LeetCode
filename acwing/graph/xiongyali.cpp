#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int N = 510;

int n1, n2, m;

vector<int> g[N]; // 数组化vector, 可以当链表来存很方便
bool st[N]; // 已有男朋友
int match[N];

bool find(int x)
{
    for(auto j:g[x])
    {
        if(st[j]) continue;
        st[j] = true;
        if(match[j] == 0 || find(match[j]))
        {
            match[j] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int count = 0;
    for(int i = 1; i <= n1; i++)
    {
        //  由于 st 没有回溯，main()中要重置 st
        memset(st, 0, sizeof st);
        if(find(i)) count++;
    }
    cout << count << endl;
    return 0;
}

