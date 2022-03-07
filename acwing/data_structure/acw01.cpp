#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
// 单链表
// 输入格式
// 第一行包含整数 M，表示操作次数。

// 接下来 M 行，每行包含一个操作命令，操作命令可能为以下几种：

// H x，表示向链表头插入一个数 x。
// D k，表示删除第 k 个插入的数后面的数（当 k 为 0 时，表示删除头结点）。
// I k x，表示在第 k 个插入的数后面插入一个数 x（此操作中 k 均大于 0）。

// idx 表示第几个插入, 
int head, e[N], ne[N], idx;
int m;

void init()
{
    head = -1;
    idx = 0;
}

// 从头加入
void add(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

// 从第k个加入
void add_k(int k, int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

// 删除第k个节点的后面一个节点
void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    cin >> m;
    init();

    while(m--)
    {
        char op;
        int k, x;
        cin >> op;

        if (op == 'H')
        {
            cin >> x;
            add(x);
        }
        else if(op == 'D')
        {
            cin >> k;
            // idx是从0开始的

            // 删除链表头
            if(!k)
                head = ne[head];
            remove(k - 1);
        }
        else{
            cin >> k >> x;
            add_k(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
    {
        printf("%d ", e[i]);
    }

    return 0;
}