// 240. 搜索二维矩阵 II
// 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

// 每行的元素从左到右升序排列。
// 每列的元素从上到下升序排列。

#include <bits/stdc++.h>

using namespace std;

// 从左下角开始搜
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int x = n-1, y = 0;
        while(x >= 0 && y < m)
        {
            if(matrix[x][y] < target)
            {
                y++;
            }
            else if(matrix[x][y] > target)
            {
                x--;
            }
            else{
                return true;
            }
        }
        return false;
    }
};