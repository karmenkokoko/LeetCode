#include<stdio.h>
#include<iostream>

using namespace std;

class Pointer{
    public:
        Pointer(){};

        void pointer_init(){
            /* 声明指针的方式 */
            int a = 10;
            int *p = &a;
            cout<<p<<endl;
            /* output 0x61fe14 address */
        } 

        void refernece_init(){
            /* 声明引用的方式 */
            int a = 10;
            int &p = a;
            cout<<p<<endl;
            /* output 10 */
        }
};

int main(int argc, char** argv){

    Pointer p = Pointer();
    p.refernece_init();
    return 0;
}