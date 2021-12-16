#include <iostream>
#include "standard_1.h"
using namespace std;

// static 常量定义在实现文件
const double CostEstimate::FudgeFactor = 1.35;

void f(const int& a)
{
    cout << a << endl;
}

int main(){
    int a = 5, b = 0;
    callWithMax(a, b);

    return 0;
}