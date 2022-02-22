#include <bits/stdc++.h>

using namespace std;
// 高精度减法
string a, b;
vector<int> A, B;

bool cmp(vector<int>& A, vector<int>& B)
{
    if(A.size() != B.size())
        return A.size() > B.size();
    // 从高位开始比
    for (int i = A.size() - 1; i >= 0; i--)
    {
        if(A[i] != B[i])
        {
            return A[i] > B[i];
        }
    }
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B)
{
    vector<int> res;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if(i < B.size())
            t = t - B[i];
        res.push_back((t + 10) % 10);
        if(t < 0)
            t = 1;
        else
            t = 0;
    }
    // 减下来的0要处理
    while(res.size() > 1 && res.back() == 0)
        res.pop_back();
    return res;
}

int main()
{
    cin >> a >> b;
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');
    
    vector<int> C;
    // 不要忘记负号
    if(cmp(A, B)) C = sub(A, B);
    else
        C = sub(B, A), cout << "-";
    
    
    for(int i = C.size()-1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }
    
    return 0;
}