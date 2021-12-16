#include <iostream>

using namespace std;

// static 对象 ，寿命从构造出来刀程序结束为止

class FileSystem{
    public:
        size_t numDisks(){}
};
// 用函数来替换static 返回一个reference来指向上述对象
// 这种特性最好加上inline
// 在多线程下手工调用所有reference-returning函数来消除多线程竞争

// 尽量使用local static
// 会在被调用期间初始化
inline
FileSystem& tfs()
{
    static FileSystem fs;
    return fs;
}
class Dictionary{
    private:
        size_t disks;
};
/*
Dictionary::Dictionary()
{
    disks = tfs().numDisks();
}
*/


int main()
{
    int x = 0;
    const char* text = "A C-style string";
}