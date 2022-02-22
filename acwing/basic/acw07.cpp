#include <bits/stdc++.h>

using namespace std;
// 高精度加法
const int N = 100010;

string a, b;
vector<int> A, B;

vector<int> add(vector<int>& A, vector<int>& B)
{
    int t = 0;
    vector<int> res;
    
    for(int i = 0; i < A.size(); i++)
    {
        if(i < B.size()) t += B[i];
        t += A[i];
        res.push_back(t % 10);
        t /= 10;
    }
    
    if(t) res.push_back(t);
    
    return res;
}

int main()
{
    // 用string a, b来存高精度数组
    cin >> a >> b;
    if(a.size() < b.size()) swap(a, b);
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');
    
    vector<int> C;
    C = add(A, B);
    
    for(int i = C.size()-1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }
    
    return 0;
}