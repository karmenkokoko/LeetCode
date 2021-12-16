#ifndef __standard_2__
#define __standard_2__

const int N = 1e6+10;

class Const_Edu{
    //const 指示
    public:
        char greeting[N] = "Hello";
        char *p = greeting;
        //const char *p = greeting; 被指的东西是不变的
        //char* const p = greeting; 指针是const
        // 被指物与指针都是常量
        //const char* const p = greeting; 

};

class Rational{};
const Rational operator* (const Rational& lhs, const Rational& rhs);

// 

#endif