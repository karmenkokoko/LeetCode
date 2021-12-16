#include <iostream>
#include <memory>
#include "standard_6.h"

using namespace std;

void f()
{
    // 声明一个智能指针,可以析构函数自动队所指对象调用delete
    // unique_ptr<Investment> pInv(createInvestment());
}

int main()
{
    Investment* createInvestment();
    // 我们创建了一个指针
    Investment* pInv = createInvestment();
    delete pInv;
}
