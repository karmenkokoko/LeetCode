## ---------条款1------------

* 最好用const 来替换#defines 对于常量来说
* inclass 定义static const 初值是不被允许的
* 我们使用enum {}来hack定义

### 对于函数的define宏
* 我们使用inline函数来替换defines
* 内联函数 inline 避免频繁调用函数对栈内存的重复开辟

### stack heap static
* stack自动分配
* heap需要malloc delete 不然会内存溢出

### 4个阶段
* 预处理，编译，汇编，链接


## ---------条款2------------

### 尽量使用const
* const指针和const数据有区别 *左边是数据，右边指示指针
* const 在函数再前方修饰返回值, 后方修饰成员函数
* 一般不改变const成员函数的值，但是如果造成程序有风险(空指针)可以用mutable来消除bitwise constness约束

## ---------条款3------------

### 对象一定要初始化
* 赋值和初始化是不同的 member initialization list
* 函数内static属于Local static
* non-local static从程序开始到程序结束, 尽量使用单例模式singleton
* inline函数返回static的类对象调用类变量 = local static

## ---------条款4------------

### 三个函数
* 拷贝构造，拷贝赋值，析构函数 都是public且inline的
* 编译器产出的析构函数是non-virtual的
* 在拷贝赋值时，编译器会拒绝修改reference对象指向不同的对象， 拒绝修改const成员

### 不用自动生成的4个函数应该明确拒绝
* private
* 或者继承父类，父类拥有private的拷贝构造和拷贝赋值

## ---------条款5------------

### virtual
* 如果父类有一个non-virtual的析构函数, 那么如果一个子类对象被父类指针删除，那么子类必有对象没被销毁
* virtual ~class();要这样
* vptr是指向函数的指针构成的数组
* 至少有一个virtual函数才将析构声明virtual
* 多态性质应该声明virtual析构函数

### 析构函数处理异常
* 设计一个函数来编写新的close函数，实在不行才用try catch
* 析构函数吐出异常比较危险

## ----------条款6------------

### base class构造函数早于子类
* virtual函数的调用不要在构造和析构期间调用。virtual函数调用不会传到derived class

### 令=返回this指针
* 自我=赋值时需要加入if(this == & rhs) identity test
* 或者交换两个指针swap
* copy构造，构造，赋值
* 写拷贝构造或者operator=时 在derived class中需要赋值base class的所有成分

## --------资源管理-----------

* 获得资源后需要立即放进管理对象
* 析构函数确保其被释放
* 智能指针不要指向同一个对象 autoptr, 指向同一对象后会被置为null
* 计数型不能打破环状引用 shared ptr auto_ptr

* RAII对象 复制时，可能会被抑制，或者采取计数法

### 显式转换对象
* shared_ptr auto_ptr.get()  = 指针取值操作符->， * 
* get是取指针里面的类型

* 重要！！！！！！！！！！！！！！！！
* new delete要成对相同！
* new []      delete []

* 多句生成智能指针 不然可能会造成内存泄漏
```
    std::tr1::shared_ptr<Widget> pw(new Widget);
    func(pw, priority)
```
## --------设计与声明------------

* shared_ptr 自动的调用删除器
```
std::tr1::shared_ptr<investment> pt(static_cast<intvestment* >(0), shanchuqi);
```

* 阻止误用，类型，资源管理责任，束缚对象值

