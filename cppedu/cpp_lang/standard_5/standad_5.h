#ifndef _standard_5__
#define _standard_5__

//在连续赋值时, 需要返回一个reference 指向操作符的左侧实参

class Widget{
    public:
        Widget& operator=(const Widget& rhs)
        {
            return *this;
        }
};
//reference to *this

class Bitmap{};
class Wid{
    private:
        Bitmap* pb;
};

Wid&
Wid::operator=(const Wid&  rhs)
{
    // 直接delete pb可能会造成自我复制错误，因为rhs.pb和this.pb可能是同一个pb
    if(this == &rhs) return *this;

    delete pb;
    pb = new Bitmap(*rhs.pb);
    return *this;

    /*
    Bitmap*  pOrig = pb;
    pb = new Bitmap(*rhs.pb);
    delete pOrig;
    return *this;
    */
}

// copy时应该copy所有成员变量，所有base class成分


#endif