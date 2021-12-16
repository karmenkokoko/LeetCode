#include "rectangle.h"


//重写继承的构造函数
Rectangle::Rectangle(const std::string &name, const int length, const int width):Polygon(4, name){
    this->length = length;
    this->width = width;
}

explicit Rectangle::Rectangle(std::string &name):Polygon(4, name){
    this->length = 1;
    this->width = 1;
}

int Rectangle::Area() {
    return length * width;
}