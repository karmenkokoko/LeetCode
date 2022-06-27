/* cpp内存管理 */
// 1. 栈 stack
// 2. 堆 heap 需要new
// 3. 自由存储 malloc
// 4. 全局静态存储区
// 5. 常量存储区

// BSS未初始化全局变量和静态变量

/* 内存对齐 */
// struct, class, union
#include <bits/stdc++.h>
using namespace std;


union example
{
    int a[5];
    char b;
    double c;
};
/*
如果以最长20字节为准，内部double占8字节，这段内存的地址0x00000020并不是double的整数倍，
只有当最小为0x00000024时可以满足整除double（8Byte）同时又可以容纳int a[5]的大小，所以正确的结果应该是result=24
*/

struct example2{
    int a[6];
    char b;
    double c;
} test_struct;

struct example3{
    char b;
    double c;
    int a;
} test_s;
/*
字节对齐除了内存起始地址要是数据类型的整数倍以外，
还要满足一个条件，那就是占用的内存空间大小需要是结构体中占用最大内存空间的类型的整数倍，
所以20不是double（8Byte）的整数倍，我们还要扩充四个字节，最后的结果是result=24
*/

int main()
{
    int result = sizeof(example);
    int result2 = sizeof(test_struct);
    int result3 = sizeof(test_s);

    cout << result << " " << result2 << " " << result3 << endl;
    return 0;
}
