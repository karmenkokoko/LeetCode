// use const as well as possible
#include <iostream>
#include <cstring>
#include "standard_2.h"

using namespace std;
class TextBlock{
    public:
        TextBlock(char* const str): text(str){};
        const char& operator[] (std::size_t position) const{
            return text[position];
        }
        // bitwise const  => 这是编译器认为的
        // const后方修饰了成员函数 此时成员函数内部不能改变任何成员变量的值
        // const前方修饰了返回值
        /*
        char& operator[] (std::size_t position) const(const 修饰的是this){
            return text[position];
        }
        */

        // 为non-const 函数调用其const兄弟
        // 两次转型 1. *this  From TextBlock& -> const TextBlock&  
        // 安全转型static_cast
        // 2.去除const const_cast
        char& operator[] (std::size_t position)
        {
            return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
        }
        const void get_char() const{
            cout << *(text + 1) << endl;
        }
    private:
        char* text;
};

class CTextBlock{
    public:
        size_t length() const;
    private:
        char* pText;
        // 其中可以mutable来始放non static成员变量的bitwise constness约束
        mutable size_t text_Length;
        mutable bool lengthisValid;
};
// 逻辑上的const
size_t CTextBlock::length() const{
    if(!lengthisValid)
    {
        text_Length = strlen(pText);
        lengthisValid = true;
    }
    return text_Length;
}

int main()
{
    char str[] = "hello";
    char* H_p = str;
    const TextBlock cctb(H_p);
    // bitwise const 
    // 这样又可以改变内部的值,但只是调用了const的成员函数。
    // char* pc = &cctb[0];   
    // *pc = 'J';
    cctb.get_char();
    return 0;
}