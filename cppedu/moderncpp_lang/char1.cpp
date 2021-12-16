#include <iostream>

using namespace std;

// 模板推导 auto

// Paramtype是一个指针或者reference
template<typename T>
void f(const T& param);


// Paramtype是一个通用refernce


// paramtype是传值


int main()
{
    int x = 27;
    const int cx = x;
    const int& rx = cx;
    
}