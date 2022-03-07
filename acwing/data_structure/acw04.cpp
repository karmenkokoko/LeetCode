#include <bits/stdc++.h>

using namespace std;
// 给定一个表达式，其中运算符仅包含 +,-,*,/（加 减 乘 整除），可能包含括号，请你求出表达式的最终值。

stack<char> op;
stack<int> nums;

void calculate()
{
    int a = nums.top();
    nums.pop();
    int b = nums.top();
    nums.pop();
    char x = op.top();
    op.pop();

    int c;
    if(x == '+') c = a + b;
    else if(x == '-')
        c = b - a;
    else if(x == '*')
    {
        c = a * b;
    }
    else
        c = b / a;
    
    nums.push(c);
}

int main()
{
    unordered_map<char, int> map = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        auto c = str[i];
        if (isdigit(str[i]))
        {
            int j = i;
            int out = 0;
            while (j < str.size() && isdigit(str[j]))
            {
                out = out * 10 + str[j] - '0';
                j++;
            }
            nums.push(out);
            // 会多加一次
            i = j-1;
        }
        else if(str[i] == '(')
        {
            op.push(str[i]);
        }
        else if(str[i] == ')')
        {
            while(op.top() != '(')
                calculate();
            op.pop();
        }
        else{
            // 先计算优先级高的，如果运算符优先级比当前这个高
            // (表示还在括号内，先全部进来
            while(op.size() && op.top() != '(' && map[op.top()] >= map[c])
                calculate();
            op.push(c);
        }
    }
    while(op.size())
        calculate();

    cout << nums.top() << endl;
    return 0;
}