#include <bits/stdc++.h>

using namespace std;

// 高精度加法
class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> A;
        vector<int> B;
        vector<int> C;

        for(int i = num1.size() - 1; i >= 0; i--) A.push_back(num1[i] - '0');
        for(int i = num2.size() - 1; i >= 0; i--) B.push_back(num2[i] - '0');

        if(A.size() > B.size() ) C = add(A, B);
        else C = add(B, A);
        string res;
        for(int i = C.size() - 1; i >= 0; i--)
        {
            res += to_string(C[i]);
        }
        return res;

    }

    vector<int> add(vector<int> &A, vector<int> &B)
    {
        int t = 0;
        vector<int> C;
        for(int i = 0; i < A.size(); i++)
        {
            if(i < B.size()) t += A[i] + B[i];
            else t += A[i];
            C.push_back(t%10);
            t /= 10;
        }

        if(t) C.push_back(t);
        return C;
    }
};