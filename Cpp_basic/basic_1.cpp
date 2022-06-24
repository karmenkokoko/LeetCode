/* C和CPP的区别 */
// 1. C++面向对象, C面向过程
// 2. Cpp有新的特性改善安全性，例如智能指针, Const常量， cast转换等等
// 3. Cpp复用性高， 引入模板开发stl


/* cpp的结构体和类的区别 */
struct A{
    int iNuml; // 这个权限是public的
};
class B{
    int iNuml; // private 权限
};

// class可以定义模板参数
template<typename T, typename Y> // typename可以定义为class
int Func(const T& t, const Y& y)
{
    // todo
}


/* C和Cpp结构体的区别 */
// 1. C结构体中不允许函数的存在，Cpp可以 
// 2. 访问权限
// 3. C不可继承， C++可以
// 4. C中必须加上struct， Cpp可以省略


/* include的顺序 */
#include <bits/stdc++.h> // 头文件路径 -> 系统变量
// #include "any.h" // 当前头文件目录 -> 编译器的头文件路径 -> 系统变量


/* 导入C自带函数的关键字extern */

