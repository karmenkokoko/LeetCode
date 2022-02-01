#include <bits/stdc++.h>

using namespace std;

// 判断是否是有效的数独
class Solution {
public:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
    bool isValidSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                else{
                    int n = board[i][j] - '1';
                    if(rows[i].test(n) || cols[j].test(n) || cells[i/3][j/3].test(n))
                    {
                        return false;
                    }
                    else{
                        rows[i] |= 1 << n;
                        cols[j] |= 1 << n;
                        cells[i/3][j/3] |= 1 << n;
                    }
                }
            }
        }
        return true;
    }
};