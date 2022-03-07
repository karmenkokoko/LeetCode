#include <bits/stdc++.h>

using namespace std;
const int N = 100010;
int n, m;
int p[N];

int find(int x)
{
    if(p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        p[i] = i;
    
    while(m--)
    {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if(op == "M")
        {
            p[find(a)] = find(b);
        }
        else{
            string res = (find(a) == find(b)) ? "Yes" : "No";
            cout << res << endl;
        }
    }

    return 0;
}