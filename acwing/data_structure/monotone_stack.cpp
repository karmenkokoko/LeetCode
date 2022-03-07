// 单调栈 找出数列中每个数字之前比他小的第一个数

#include <iostream>

using namespace std;

const int N = 100010;

int stk[N];
int n, arr[N];

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int top = 0;
    for(int i = 0; i < n; i++)
    {
        while(top && stk[top] >= arr[i]) top--;
        if(top) printf("%d ", stk[top]);
        else printf("-1 ");
        stk[++top] = arr[i];
    }
    
    return 0;
}