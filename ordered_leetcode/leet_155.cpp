#include <stack>
#include <iostream>
using namespace std;
// 最小栈
// 用辅助栈来做
// 注意辅助栈需要保持一直有值

class MinStack {
private:
    stack<int> stk;
    stack<int> min_stk;
public:
    MinStack(){
    }
    
    void push(int val) {
        if(min_stk.empty() || val <= min_stk.top())
        {
            min_stk.push(val);
            stk.push(val);
        }
        else{
            stk.push(val);
        }
    }
    
    void pop() {
        if (min_stk.top() == stk.top())
        {
            min_stk.pop();
            stk.pop();
        }
        else{
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};
