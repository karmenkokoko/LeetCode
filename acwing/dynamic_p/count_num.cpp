#include <iostream>
// 统计a到b范围内0-9各个数字出现的次数
using namespace std;

const int N = 100010;
int a, b, num[N];

int get_num(int l, int r)
{
    int ans = 0;
    for (int i = l; i >= r; i--)
    {
        ans = ans * 10 + num[i];
    }
    return ans;
}

int pow_10(int x)
{
    int ans = 1;
    while(x)
    {
        ans *= 10;
        x--;
    }
    return ans;
}

int get_count(int n, int x)
{
    if(!n)
        return 0;
    int cnt = 0;
    while(n)
    {
        num[++cnt] = n % 10;
        n /= 10;
    }
    int ans = 0;

    if(x)
    {
        for (int i = cnt; i >= 1; i--)
        {
            ans += get_num(cnt, i + 1) * pow_10(i - 1);
            if(num[i] > x)
                ans += pow_10(i - 1);
            else if(num[i] == x)
                ans += get_num(i - 1, 1) + 1;
            else
                ans += 0;
        }
    }
    else{
        for (int i = cnt; i >= 1; i--)
        {
            ans += (get_num(cnt, i + 1)-1) * pow_10(i - 1);
            if(num[i] > x)
                ans += pow_10(i - 1);
            else if(num[i] == x)
                ans += get_num(i-1, 1) + 1;
            else
                ans += 0;
        }
    }
    return ans;
}

int main()
{
    while(scanf("%d%d", &a, &b) && a!=0 && b!=0)
    {
        if(a > b)
            swap(a, b);
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            ans = get_count(b, i) - get_count(a-1, i);
            printf("%d ", ans);
        }
        cout << endl;
    }
    return 0;
}