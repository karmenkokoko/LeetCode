#include <bits/stdc++.h>
using namespace std;
// 43. 字符串相乘
// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

// 高精度加法和高精度乘法
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0"; // 特殊情况判断
        vector<int> A;
        vector<int> B;
        vector<int> C;

        for(int i = num1.size()-1; i >= 0; i--) A.push_back(num1[i] - '0');
        for(int i = num2.size()-1; i >= 0; i--) B.push_back(num2[i] - '0');

        vector<int> res;
        for(int i = 0; i < B.size(); i++)
        {
            C = multi(A, B[i]);
            if(i > 0) C.insert(C.begin(), i, 0);
            res = add(C, res);
        }

        string ans;

        for(int i = res.size()-1; i >= 0; i--)
        {
            ans += to_string(res[i]);
        }
        return ans;
    }

    vector<int> multi(vector<int> &A, int b)
    {
        
        int t = 0;
        vector<int> C;
        for(int i = 0; i < A.size() || t; i++)
        {
            if(i < A.size()) t += A[i] * b;
            C.push_back(t % 10);
            t /= 10;
        }
        if(!b) return C; // 特别情况，加的时候还是需要多位0
        while(C.size() > 1 && C.back() == 0) C.pop_back();
        return C;
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