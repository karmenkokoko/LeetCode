#include<iostream>
 
using namespace std;
 
class Test
{
public:
    Test(){}
    Test(int _m):_cm(_m){}
    int get_cm() 
    {
       return _cm;
    }
 
private:
    int _cm;
};
 
 
 
void Cmf(Test& _tt)
{
    cout<<_tt.get_cm();
}
 
int main(void)
{
    Test t(8);
    Cmf(t);
    t.get_cm();
    system("pause");
    return 0;
}