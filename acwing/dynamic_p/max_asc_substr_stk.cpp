#include <iostream>
#include <stack>
#include <vector>

using namespace std;

const int N = 100010;

int n;
int arr[N];
vector<int> stk;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(stk.empty() || stk.back() < arr[i])
        {
            stk.push_back(arr[i]);
        }
        else{
            *lower_bound(stk.begin(), stk.end(), arr[i]) = arr[i];
        }
    }
    cout << stk.size() << endl;
    return 0;
}