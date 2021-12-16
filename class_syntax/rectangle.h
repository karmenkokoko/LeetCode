#include<string>
#include"polygon.h"

class Rectangle:public Polygon{
    private:
        int length;
        int width;
    
    public:
        explicit Rectangle(std::string &name);
        //explicit关键字 表明该构造函数时显式的 只能修饰单参数构造函数
        Rectangle(const std::string &name, const int length, const int width);

        const int GetLength(void) const {return this->length;}
        void Setlength(const int) {this->length = length;}

        const int Getwidth(void) const {return this->width;}
        void SetWidth(const int) {this->width = width;}

        int Area();
};