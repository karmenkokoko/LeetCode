#include <iostream>
#include <stdio.h>

using namespace std;

class Fibonacci{
    public:
        Fibonacci(){};

        int fib(int n){
            if(n==0) return 0;
            if(n==1) return 1;

            int f_0 = 0, f_1 = 1, sum = 0;
            while(n>=2){
                sum = (f_0 + f_1)%1000000007;
                f_0 = f_1;
                f_1 = sum;
                n--;
            }
            return sum;
        }
};

int main(int argc, char *argv[]){

    Fibonacci fibonacci = Fibonacci();
    cout<<fibonacci.fib(99)<<endl;
    return 0;
}