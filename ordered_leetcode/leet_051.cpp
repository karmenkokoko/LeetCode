#include <bits/stdc++.h>

using namespace std;
// N皇后
class Solution {
public:
// 列，对角线，反对角线标上记号
    vector<bool> col;
    vector<bool> diag;
    vector<bool> udiag;
    vector<string> g;
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n)
    {
        col = vector<bool>(n+1, false);
        diag = vector<bool>(2 * n + 1, false);
        udiag = vector<bool>(2 * n + 1, false);
        // string 初始化方式
        string str = string(n, '.');
        for (int i = 0; i < n; i++)
        {
            g.push_back(str);
        }
        dfs(0, g, n);
        return res;
    }

    // dfs每一行
    void dfs(int row, vector<string>& path, int n)
    {
        if(row == n)
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++)
        {
            if(!col[i] && !diag[n-row+i] && !udiag[row+i])
            {
                path[row][i] = 'Q';
                col[i] = diag[n - row + i] = udiag[row + i] = true;
                dfs(row + 1, path, n);
                col[i] = diag[n - row + i] = udiag[row + i] = false;
                path[row][i] = '.';
            }
        }
    }
    
};