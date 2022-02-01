#include <bits/stdc++.h>

using namespace std;
// 解数独

class Solution {
private:
    // 9位来存储是否已经使用过这个数字
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;

public:
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        int cnt = 0;
        // 统计要填的数量
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == '.')
                {
                    cnt++;
                    continue;
                }
                else{
                    // 记录使用过的数字
                    int n = board[i][j] - '1';
                    rows[i] |= 1 << n;
                    cols[j] |= 1 << n;
                    cells[i / 3][j / 3] |= 1 << n;
                }
            }
        }
        dfs(board, cnt);
    }

    bool dfs(vector<vector<char>>& board, int cnt)
    {
        if(cnt == 0)
            return true;
        pair<int, int> slot = get_next(board);
        auto num = get_proba_state(slot.first, slot.second);
        if(!num.count())
            return false;

        for(int n = 0; n < num.size(); n++)
        {
            // test bit value
            // 测试第n位上的数字是否是1
            if(!num.test(n))
                continue;
            // dfs过程
            fill_num(slot.first, slot.second, n, true);
            board[slot.first][slot.second] = n + '1';
            if(dfs(board, cnt-1))
                return true;
            board[slot.first][slot.second] = '.';
            fill_num(slot.first, slot.second, n, false);
        }
        return false;
    }

    pair<int, int> get_next(vector<vector<char>>& board)
    {
        pair<int, int> res;
        int min_count = 10;
        // 找出周围填的最多的数的位置
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] != '.')
                    continue;
                auto state = get_proba_state(i, j);
                // count 1的个数，所以getproba需要取个反
                if(state.count() >= min_count)
                    continue;

                min_count = state.count();
                res = {i, j};
            }
        }
        return res;
    }

    bitset<9> get_proba_state(int x, int y)
    {
        // 9位 有填入则为1， 没有填入则为0
        // 要找到一个填入最多的区域
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    void fill_num(int x, int y, int n, bool flag)
    {
        rows[x][n] = flag ? 1 : 0;
        cols[y][n] = flag ? 1 : 0;
        cells[x / 3][y / 3][n] = flag ? 1 : 0;
    }
};