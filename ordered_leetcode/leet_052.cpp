#include <bits/stdc++.h>
// N皇后返回数量
using namespace std;

class Solution{
private:
    vector<string> path;
    vector<bool> col;
    vector<bool> diag;
    vector<bool> udiag;
    vector<vector<string>> res;

public:
    int totalQueens(int n)
    {
        col = vector<bool>(n, false);
        diag = vector<bool>(2 * n + 1, false);
        udiag = vector<bool>(2 * n + 1, false);
        string str = string(n, '.');
        for (int i = 0; i < n; i++)
        {
            path.push_back(str);
        }

        dfs(path, 0, n);
        return res.size();
    }

    void dfs(vector<string>& path, int row, int n)
    {
        if(row == n)
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if(!col[i] && !diag[i+row] && !udiag[n - row + i])
            {
                col[i] = diag[i + row] = udiag[n - row + i] = true;
                path[row][i] = 'Q';
                dfs(path, row + 1, n);
                path[row][i] = '.';
                col[i] = diag[i + row] = udiag[n - row + i] = false;
            }
        }
    }
};
