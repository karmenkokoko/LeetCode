// 高精度除法
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

vector<int> divide(vector<int>& A, int b, int& r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        // 用余数来存
        r = r * 10 + A[i];
        C.push_back(r / b);
        r = r % b;
    }
    reverse(C.begin(), C.end());
    while(C.size()>1 && C.back() == 0) C.pop_back();

    return C;
}

int main()
{
    string a;
    int b;
    cin >> a >> b;
    vector<int> A;
    for (int i = a.size()-1; i >= 0; i--)
        A.push_back(a[i] - '0');
    vector<int> C;

    int r = 0;
    C = divide(A, b, r);

    for (int i = C.size() - 1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }

    cout << endl;
    printf("%d", r);
    return 0;
}