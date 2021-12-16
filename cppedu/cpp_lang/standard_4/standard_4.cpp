#include <iostream>
#include <vector>
#include "standard_4.h"

using namespace std;

void doSomething()
{
    vector<Widget> v;
    // v 被销毁
}


int main()
{
    Empty e1;
    Empty e2(e1); // 拷贝构造
    e2 = e1;

    NamedObject<int> no1("Sammmm!", 2);
    NamedObject<int> no2(no1);

    // DBConn dbc(DBConnection::create());
    printf("OK");
}