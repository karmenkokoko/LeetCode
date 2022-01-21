#include <iostream>
// 最长公共子序列
using namespace std;
const int N = 1010;

int n, m;
char A[N], B[N];
int f[N][N];


int main()
{
    cin >> n >> m;
    scanf("%s%s", A+1, B+1);
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = max(f[i-1][j], f[i][j-1]);
            if(A[i] == B[j]) f[i][j] = max(f[i][j], f[i-1][j-1] + 1);
            else f[i][j] = max(f[i][j], f[i-1][j-1]);
        }
    }
    
    cout << f[n][m] << endl;
    return 0;
    
}