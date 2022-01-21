#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public:
        string minNumber(vector<int>& nums)
        {
            vector<string> str;
            for(int num : nums)
            {
                str.push_back(to_string(num));
            }
            quicksort(str, 0, str.size()-1);
        }

        void quicksort(vector<string>& str, int l, int r)
        {
            if(l >= r) return ;
            int i = l-1, j = r + 1;
            string mid = str[(l+r) >> 1];

            while(i < j)
            {
                // x + y < y + x  =>  x < y
                do i++; while(str[i] + mid < mid + str[i]);
                do j--; while(str[j] + mid > mid + str[j]);
                if(i < j) swap(str[i], str[j]);
            }
            quicksort(str, l, j);
            quicksort(str, j+1, r);
        }
};