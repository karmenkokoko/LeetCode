#include <bits/stdc++.h>

using namespace std;
const int N = 1000010;
int n, h[N], ph[N], hp[N], cnt, m;
// 维护一个集合，初始时集合为空，支持如下几种操作：

// I x，插入一个数 x；
// PM，输出当前集合中的最小值；
// DM，删除当前集合中的最小值（数据保证此时的最小值唯一）；
// D k，删除第 k 个插入的数；
// C k x，修改第 k 个插入的数，将其变为 x；
// 现在要进行 N 次操作，对于所有第 2 个操作，输出当前集合的最小值。

// 输入格式
// 第一行包含整数 N。

// 接下来 N 行，每行包含一个操作指令，操作指令为 I x，PM，DM，D k 或 C k x 中的一种。

// 输出格式
// 对于每个输出指令 PM，输出一个结果，表示当前集合中的最小值。

// 每个结果占一行。


// 输入的是堆的坐标
void swap_heap(int x, int y)
{
    swap(ph[hp[x]], ph[hp[y]]);
    swap(hp[x], hp[y]);
    swap(h[x], h[y]);
}

void down(int x)
{
    int t = x;
    if(2 * x <= cnt && h[t] > h[2 * x]) t = 2 * x;
    if(2 * x + 1 <= cnt && h[t] > h[2 * x + 1])
        t = 2 * x + 1;
    if(t != x)
    {
        swap_heap(t, x);
        down(t);
    }
}

void up(int x)
{
    while(x/2 && h[x/2] > h[x])
    {
        swap_heap(x / 2, x);
        x >>= 1;
    }
}


int main()
{
    cin >> n;
    m = 0;
    cnt = 0;
    while (n--)
    {
        string op;
        cin >> op;
        if(op == "I")
        {
            int x;
            cin >> x;
            m++;
            cnt++;
            ph[m] = cnt, hp[cnt] = m;
            h[cnt] = x;
            up(cnt);
        }
        else if(op == "PM")
        {
            printf("%d\n", h[1]);
        }
        else if(op == "DM")
        {
            swap_heap(1, cnt);
            cnt--;
            down(1);
        }
        else if(op == "D")
        {
            int k;
            cin >> k;
            k = ph[k];
            swap_heap(k, cnt);
            cnt--;
            down(k);
            up(k);
        }
        else{
            int k, x;
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            up(k);
            down(k);
        }
    }
    return 0;
}