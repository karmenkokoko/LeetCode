#ifndef __standard_1__
#define __standard_1__
// #define CALL_WITH_MAX(a, b) f((a) > (b) ? (a):(b))
template<typename T>
inline void f(const T& a)
{
    printf("Ok");
}
// 形似函数的宏用inline 函数替换#defines
// 编译器调用inline function 可以把整个函数体的代码插入调用语句处
template <typename T>
inline void callWithMax(const T& a, const T& b)
{
    f(a > b ? a:b);
}

class CostEstimate{
    private:
    // 以const对象 enums来替换#defines
        static const double FudgeFactor;
};

// enum hack
class Gameplayer{
    private:
        enum { NumTurns = 5};
        int score[NumTurns];
};



#endif