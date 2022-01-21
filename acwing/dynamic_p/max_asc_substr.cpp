#include <iostream>
// 最长上升子序列
using namespace std;

const int N = 10010;

int n;
int arr[N];
int f[N];
// 
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int res = 1;
    for(int i = 1; i <= n; i++)
    {
        f[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
            {
                f[i] = max(f[i], f[j]+1);
            }
        }
        res = max(res, f[i]);
    }

    cout << res << endl;
}