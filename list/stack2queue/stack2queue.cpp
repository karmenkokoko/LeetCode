#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class CQueue{

    private:
        stack<int> stack1, stack2;
    
    public:
        CQueue(){

        }//constuction function

        void Input(int value){
            stack1.push(value);
        }

        int Output(){
            //First condition stack1 is empty
            if(stack1.empty()){
                return -1;
            }
            //2
            while(!stack1.empty()){
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            // output 
            int res = stack2.top();
            stack2.pop(); //just delete
            while(!stack2.empty()){
                int temp = stack2.top();
                stack2.pop();
                stack1.push(temp);
            }
            return res;
        }
};

int main(int argc, char* argv[]){
    CQueue* stack_queue = new CQueue();
    int balance[2];
    stack_queue->Input(3);
    balance[0] = stack_queue->Output();
    balance[1] = stack_queue->Output();
    cout<<balance[0]<<" "<<balance[1]<<endl;
    return balance[0];
};