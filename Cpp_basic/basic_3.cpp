#include <iostream>
#include <string.h>
using namespace std;

// class A
// {
// public:
//     virtual void fun()
//     {
//         cout << "A \n";
//     }
// };
// class B :public A
// {
// public:
//     virtual void fun()
//     {
//         cout << "B \n";
//     }
// };

int func(int a,double b)
{
    return ((a)+(b));
}
int func(double a,float b)
{
    return ((a)+(b));
}
int func(float a,int b)
{
    return ((a)+(b));
}


/* 拷贝构造（浅拷贝） 和初始化拷贝 */
class constructors{
    int i;
    int *p;
public:
    constructors(int ai, int value)
    {
        i = ai;
        p = new int(value);
    }
    ~constructors()
    {
        delete p;
    }
    //拷贝构造
    constructors(const constructors &t)
    {
        this->i = t.i;
        this->p = new int(*t.p);
    }

};
// 一个类会自动生成， 默认构造函数，拷贝构造， 赋值运算符，以及析构函数
// 深拷贝构造函数 和 赋值运算符
class STRING{
    char *_str;
public:
    STRING(const STRING &s)
    {
        //_str = s._str;
        _str = new char[strlen(s._str) + 1];
        // strcpy_s( _str, strlen(s._str) + 1, s._str );
    }
    STRING& operator=(const STRING& s)
    {
        if (this != &s)
        {
            //this->_str = s._str;
            delete[] _str;
            this->_str = new char[strlen(s._str) + 1];
            // strcpy_s(this->_str, strlen(s._str) + 1, s._str);
        }
        return *this;
    }
};

/* 多态 */
// 父类构造函数–>成员类对象构造函数–>自身构造函数
// 子类转父类 dynamic_cast安全， 父类转子类不安全
// 静态多态（函数重载）， 动态多态（虚函数）
/* 协变， 基类类型的指针函数 */
class Base
{
public:
    virtual Base* FunTest()
    {
        cout << "victory" << endl;
        return this;
    }
};
 
class Derived :public Base
{
public:
    virtual Derived* FunTest()
    {
        cout << "yeah" << endl;
        return this;
    }
};

/* 模板类 */
template<class T>
struct TemplateStruct
{
    TemplateStruct()
    {
        cout << sizeof(T) << endl;
    }
};
// #2 模板显示实例化
template struct TemplateStruct<int>;
 
// #3 模板具体化
template<> struct TemplateStruct<double>
{
    TemplateStruct() {
        cout << "--8--" << endl;
    }
};


class Example6 {
    string* ptr;
public:
    Example6 (const string& str) : ptr(new string(str)) {}
    ~Example6 () {delete ptr;}
    // 移动构造函数，参数x不能是const Pointer&& x，
    // 因为要改变x的成员数据的值；
    // C++98不支持，C++0x（C++11）支持
    Example6 (Example6&& x) : ptr(x.ptr)
    {
        x.ptr = nullptr;
    }
    // move assignment
    Example6& operator= (Example6&& x)
    {
        delete ptr;
        ptr = x.ptr;
        x.ptr=nullptr;
        return *this;
    }
    // access content:
    const string& content() const {return *ptr;}
    // addition:
    Example6 operator+(const Example6& rhs)
    {
        return Example6(content()+rhs.content());
    }
};

/* 虚继承 */
// 解决二义性
class A{
public:
    int _a;
};
class B :virtual public A
{
public:
    int _b;
};
class C :virtual public A
{
public:
    int _c;
};
class D :public B, public C
{
public:
    int _d;
};

/* 纯虚函数和虚函数 */
// 纯虚函数实现一个接口，规范派生类的行为，派生类必须提供一个具体的实现
// 有纯虚函数才可以被成为抽象类

/* 虚析构函数的主要作用是 防止内存泄漏 */

/* 仿函数类 行使函数功能的类 */
class function{
    // 仿函数体内必须重载()
    public:
        void operator()(const string &str) const{
            cout << str << endl;
        }
};
// 仿函数， 计算小于一个长度的字符串的个数, count_if需要的是一个函数指针， 并且只有一个参数作为他最后一个参数
class ShorterThan {
    public:
        explicit ShorterThan(int maxLength) : length(maxLength) {}
        bool operator() (const string& str) const {
            return str.length() < length;
        }
    private:
        const int length;
};



int main()
{
    // A *a = new B();
    // a->fun();//输出B，A类中的fun在B类中重写
    
    constructors t1(1, 2);
    constructors t2(t1);

    // Base b;
    // Derived d;
    // b.FunTest();
    // d.FunTest();

    TemplateStruct<int> intStruct;
    TemplateStruct<double> doubleStruct;
    TemplateStruct<char> llStruct;

    Example6 foo("Exam");           // 构造函数
    // Example6 bar = Example6("ple"); // 拷贝构造函数
    Example6 bar(move(foo));     // 移动构造函数
                                // 调用move之后，foo变为一个右值引用变量，
                                // 此时，foo所指向的字符串已经被"掏空"，
                                // 所以此时不能再调用foo
    bar = bar+ bar;             // 移动赋值，在这儿"="号右边的加法操作，
                                // 产生一个临时值，即一个右值
                                 // 所以此时调用移动赋值语句
    cout << "bar's content: " << bar.content() << '\n';

    cout << sizeof(A) << " " << sizeof(B) << " " << sizeof(C) << endl;
    cout << sizeof(D) << endl;
    // sizeof 看编译器
    function Myfunc;
    Myfunc("hello!! 仿function");

    return 0;
}