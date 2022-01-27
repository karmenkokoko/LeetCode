#include <bits/stdc++.h>
using namespace std;
// 01背包改版
const int N = 100010;
vector<int> w;
int c;
int f[N];
// 网易内部开了一家水果店，最近推出了一个水果礼盒的产品。礼盒总的目标重量是固定的，水果店的工人需要从N个不同重量的水果中，挑选出合适的一些水果，使尽量装满这个礼盒。但是礼盒比较脆弱，所以水果的重量总和不能超过礼盒的目标重量。

// 问每一次工人装水果的时候，这个礼盒最多能装多少。

// 输入描述:
// 第一行为水果礼盒的目标重量C，为一个正整数，0<C<=100000
// 第二行为所有可选水果的重量数组W，都为整数，用空格分隔，每个值不大于1000，0<length(W)<=10000

int main()
{
    cin >> c;
    // 输入为整数int
    w.push_back(0);
    while(1)
    {
        int temp;
        cin >> temp;
        w.push_back(temp);
        if(cin.get()=='\n') break;
    }
    int n = w.size() - 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = c; j >= w[i]; j--)
        {
            f[j] = max(f[j], f[j-w[i]]+w[i]);
        }
    }
    cout << f[c] << endl;
    return 0;
}