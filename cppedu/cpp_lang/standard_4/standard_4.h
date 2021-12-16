#ifndef __standard_4__
#define __standard_4__

class Empty{
    public:
        Empty(){} // default
        Empty(const Empty& rhs) {}  // copy constructor
        ~Empty(){}

        Empty& operator=(const Empty& rhs){}  // copy assignment operator
        // 编译器会自动的产出上面4个函数
};

template<typename T>
class NamedObject{
    public:
        NamedObject(const char* name, const T& value) {}
        NamedObject(const std::string& name, const T& value): nameValue(name), objectValue(value) {}

    private:
        std::string nameValue;
        T objectValue;

    // if string& nameValue 那将不会生成拷贝赋值函数，因为C++ 不允许reference指向不同对象

};

// 阻止拷贝
class Uncopyable{
    public:
        Uncopyable(){}
        ~Uncopyable(){}
    private:
        Uncopyable(const Uncopyable&){}
        Uncopyable& operator=(const Uncopyable&){}
};

class HomeForSale: private Uncopyable{};

// 设计工厂函数
// 局部销毁 base class 带有non-virtual函数 因此其derived成分没有被销毁
class TimeKeeper{
    public:
        TimeKeeper(){}
        virtual ~TimeKeeper(){}
};

// 抽象class 声明pure virutal析构函数
class AWOV{
    public:
        virtual ~AWOV() = 0;
};

AWOV::~AWOV(){}
// polymorphic base classes都应该声明一个virtual析构函数


class Widget{
    public:
        ~Widget(){}
};

// 析构函数必须要执行一个动作，而该动作可能会失败时抛出异常
// 创建一个用于管理DBCOONNECTION资源的class

class DBConnection{
    public:
        static DBConnection create(){}
        void close(){}
};

// 析构函数不要突出异常
// class应该提供一个函数来对异常做出反应
class DBConn{
    public:
        void close(){
            db.close();
            closed = true;
        }
        ~DBConn()
        {
            if(!closed)
            {
                try{db.close();}
                catch(std::exception& e)
                {
                    std::abort();
                }
            }
        }
    private:
        DBConnection db;
        bool closed;
};


// 对象在构造函数生成时的顺序是由base class -> derived class
class Transaction{
    public:
        explicit Transaction(const std::string& logInfo){}
        void logTransaction(const std::string& logInfo) const{} // const修饰成员函数指针this, 不能对成员变量有修改
};

Transaction::Transaction(const std::string& logInfo)
{
    logTransaction(logInfo);  // non virtual调用
}

class BuyTransaction : public Transaction{
    public:
        BuyTransaction():Transaction(createLogString()){}
    private:
        static std::string createLogString(){} // static就不会指向尚未定义的状态
};

#endif