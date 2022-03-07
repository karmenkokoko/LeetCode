#include <bits/stdc++.h>

using namespace std;
// 实现一个队列，队列初始为空，支持四种操作：

// push x – 向队尾插入一个数 x；
// pop – 从队头弹出一个数；
// empty – 判断队列是否为空；
// query – 查询队头元素。
// 现在要对队列进行 M 个操作，其中的每个操作 3 和操作 4 都要输出相应的结果。
const int N = 1000010;

int q[N];
int hh, tt;

int main()
{
    hh = 0, tt = -1;
    int m;
    cin >> m;
    while(m--)
    {
        string op;
        cin >> op;
        int x;
        if(op == "push")
        {
            cin >> x;
            q[++tt] = x;
        }
        else if(op == "pop")
        {
            hh++;
        }
        else if(op == "empty")
        {
            if(hh > tt)
            {
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else{
            printf("%d\n", q[hh]);
        }
    }
    return 0;
}