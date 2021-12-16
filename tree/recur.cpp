#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{

    public:
        Solution() {};

        int Recur(int N, vector<int>& A){
            vector<int> tmp;

            for(int i = A.size()-1; i>1; i--){
                if(A[i] < A[i-1]) continue;
                tmp.push_back(A[i]);
            }
            tmp.push_back(A[0]);
            reverse(tmp.begin(), tmp.end());
            if(A.size() == 1 || tmp.size() == N) return 0;

            return 1 + Recur(tmp.size(), tmp);

        }

};


int main(int argc, char** argv){
    Solution* p = new Solution();
    vector<int> Ai = {4, 3, 2, 3, 2, 1};
    cout<< p->Recur(Ai.size(), Ai) << endl;
    delete[] p;
}