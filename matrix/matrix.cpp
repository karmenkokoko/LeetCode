#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
        {
            return {};
        }
        
        int h = matrix.size();
        int w = matrix[0].size();
        int total = h*w;
        vector<int> path(total);
        vector<vector<bool>> visit(h, vector<bool>(w));

        path[0] = matrix[0][0];
        visit[0][0] = true;
        int dir = 0;
        int st_i = 0, st_j = 0;
        for(int i = 0; i < total-1; i++)
        {
            st_i += dx[dir];
            st_j += dy[dir];
            printf("i: %d\n", i);
            if(i==6)
            {
                printf("st_i: %d st_j: %d \n", st_i, st_j);
            }
            if(st_i >= h || st_j >= w || st_j < 0 || visit[st_i][st_j] == true)
            {
                st_i -= dx[dir];
                st_j -= dy[dir];
                dir = (dir+1) % 4;
                printf("dir: %d \n", dir);
                st_i += dx[dir];
                st_j += dy[dir];
                printf("st_i: %d st_j: %d \n", st_i, st_j);
                path[i+1] = matrix[st_i][st_j];
                printf("path: %d \n", path[i+1]);
                visit[st_i][st_j] = true;
            }
            else{
                path[i+1] = matrix[st_i][st_j];
                printf("path: %d \n", path[i+1]);
                visit[st_i][st_j] = true;
            }
        }
        return path;
        
    }
};



int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution a = Solution();
    vector<int> path = a.spiralOrder(matrix);
    for(int i = 0; i < path.size(); i++) printf("%d ", path[i]);

    return 0;
}