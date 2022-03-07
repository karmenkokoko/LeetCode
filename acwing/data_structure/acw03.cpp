#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int top;
int stk[N];

void init()
{
    // 0应该比较好判断
    top = 0;
}

int main()
{
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
            stk[++top] = x;
        }
        else if(op == "query")
        {
            printf("%d\n", stk[top]);
        }
        else if(op == "pop")
        {
            top -= 1;
        }
        else{
            if(top != 0)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}