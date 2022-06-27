#include <bits/stdc++.h>
using namespace std;

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

// // class可以定义模板参数
template<typename T, typename Y> // typename可以定义为class
int Func(const T& t, const Y& y)
{
    // todo
    return 0;
}

// /* C和Cpp结构体的区别 */
// // 1. C结构体中不允许函数的存在，Cpp可以 
// // 2. 访问权限
// // 3. C不可继承， C++可以
// // 4. C中必须加上struct， Cpp可以省略


// /* include的顺序 */
// // #include <iostream> // 头文件路径 -> 系统变量
// // #include "any.h" // 当前头文件目录 -> 编译器的头文件路径 -> 系统变量


// /* 导入C自带函数的关键字extern */
// extern "C" int strcmp(const char *s1, const char *s2) { return 0; } // extern之后 这段函数会C语言编译
// extern "C"{
//     // #include <string.h>
// }


// /* C++ -> 可执行文件 */
// // 预编译->编译->汇编->链接
// // 链接有两种，静态链接库和动态链接库, Linux .a和.so. 动态链接库删了就不能执行了.


// /* 指针和数组 */
// // 1. 赋值, 相互赋值， 一个一个拷贝
// // 2. 存储方式, 不连续， 连续
// // 3. sizeof 数组可以看大小，指针只有4字节或者8字节
// // 数组
int a[5] = {0};
char b[] = "Hello";    // 按字符串初始化，大小为6
char c[] = { 'H','e','l','l','o','\0' };    // 按字符初始化
int* arr = new int[10];    // 动态创建一维数组
// 指针
void func_1(){
    // 指向对象的指针
    int* p = new int(0);
    delete p;
    // 指向数组的指针
    int* p1 = new int[10];
    delete[] p1;
    // 指向类的指针：
    string* p2 = new string;
    delete p2;
    // 指向指针的指针（二级指针）
    int** pp = &p;
    **pp = 10;
}
// 
void func_2(){
    int a[3][4];  
    int (*p)[4];  //该语句是定义一个数组指针，指向含4个元素的一维数组
    p = a;        //将该二维数组的首地址赋给p，也就是a[0]或&a[0][0]
    p++;          //该语句执行过后，也就是p=p+1；p跨过行a[0][]指向了行a[1][]
                //所以数组指针也称指向一维数组的指针，亦称行指针。
    //访问数组中第i行j列的一个元素，有几种操作方式：
    //*(p[i]+j)、*(*(p+i)+j)、(*(p+i))[j]、p[i][j]。其中，优先级：()>[]>*。
    //这几种操作方式都是合法的。

    // char *str = "hello,douya!";
    // str[2] = 'a';
    // *(str+2) = 'b';
    //这两种操作方式都是合法的。
}


/* 函数指针 */
void func_3()
{
    // int func(int a);
    // int (*f)(int a);
    // f = &func; // 指向函数的指针变量， 指向函数的入口地址
}
// 应用场景，callback。
// stl qsort() 用自己定义的cmp
// 野指针 dangling pointer
void func_4()
{
    int *ptr = (int *)malloc(sizeof(int));
    free(ptr);
    ptr = NULL; //free指针之后置空
}


/* 静态变量 */
// 1. 静态对象仅当用到时才被构造
// 2. 作用域 全局，局部，类，语句，命名空间，文件作用域


/* malloc 和 new的区别 */
class allocate_memory{
    int a;
    public:
        int *ptr;
        allocate_memory()
        {
            printf("constructor! \n");
        }
};
void func_5(){
    allocate_memory *first = new allocate_memory;
    printf("create a \n");

    allocate_memory *b = (allocate_memory *)malloc(sizeof(allocate_memory));
    printf("create b \n");
}
// constructor! 
// create a 
// create b
// 1. new是操作符，malloc是函数
// 2. new会调用构造函数和析构函数
// 3. new更加安全
// 4. malloc内存池， 会申请大内存


/* 指针函数和函数指针 */
// 指针函数本质还是函数，返回指针
// 函数指针是一个指向函数的指针 (*ptr)(const typename parameters)
typedef struct _Data{
    int a, b;
}Data;

Data *f(int a, int b)
{
    Data *data = new Data;
    return data;
}
int add(int x, int y)
{
    return x + y;
}
int (*funcptr)(int x, int y);
void func_6()
{
    Data *mydata = f(4, 5);
    funcptr = add;
    cout << (*funcptr)(1, 2) << endl;
}


/* const 默认作用于左边，否则就是右边 */
/* 指针用法 */
void func_7(int n)
{
    int *p = NULL;
    p = (int *)malloc(sizeof(int) * n); // 申请n个内存空间
    // p = (int *)calloc(n, sizeof(int)); // 申请n个内存空间并置零
    assert(p != NULL);
    p = (int *)realloc(p, 25);
    free(p);
    p = NULL;
}
/* pass by reference, value and pointer */
void testfunc(int a, int *b, int &c){//形参a值发生了改变，但是没有影响实参i的值；但形参*b、c的值发生了改变，影响到了实参*j、k的值
    a += 1;
    (*b) += 1;
    c += 1;
    printf("a= %d, b= %d, c= %d\n",a,*b,c);//a= 2, b= 2, c= 2
}
void func_8()
{
    int i = 1;
    int a = 1;
    int *j = &a;
    int k = 1;
    testfunc(i, j, k);
    printf("i= %d, j= %d, k= %d\n",i,*j,k);//i= 1, j= 2, k= 2
}

// main 
int main()
{
    // func_1();
    func_5();
    func_6();
    func_8();
    return 0;
}
