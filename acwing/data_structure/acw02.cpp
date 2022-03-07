#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
// 双向链表;
// 两个数组来表示两个方向的next:
// 0 -> 1
// 0 <- 1

int r[N], l[N], e[N], idx;
int m;

void init()
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
    // idx从2开始
    // 保持0， 1是左右的头节点
}

// 在第k个节点之后加入x
void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx++;
}

// 删除第k个节点
void remove(int k)
{
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

int main()
{
    cin >> m;
    init();

    while(m--)
    {
        string op;
        int x, k;
        cin >> op;
        if (op == "L")
        {
            cin >> x;
            add(0, x);
        }
        else if(op == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if(op == "D")
        {
            cin >> k;
            remove(k + 1);
        }
        else if(op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else{
            cin >> k >> x;
            add(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
    {
        printf("%d ", e[i]);
    }
    return 0;
}