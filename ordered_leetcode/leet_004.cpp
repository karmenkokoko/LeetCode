#include <bits/stdc++.h>
// 寻找两个正序数组的中位数

// 第k个数, 但是边界条件很多
using namespace std;
class Solution
{
public:
    vector<int> all;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        all = vector<int> (m+n);
        int l = 0;
        int r = 0;
        int k = 0;
        while(l < n && r < m)
        {
            if(nums1[l] < nums2[r]) all[k++] = nums1[l++];
            else all[k++] = nums2[r++];
        }
        while(l < n) all[k++] = nums1[l++];
        while(r < m) all[k++] = nums2[r++];

        int mid = (m + n) >> 1;
        int sum = m+n;
        if(m && n)
        {
            if(sum & 1) return double(all[mid]);
            else return (all[mid] + all[mid-1]) / 2.;
        }
        else{
            if(!m)
            {
                if(!(n & 1)) return (all[mid] + all[mid-1]) / 2.;
                else return double(all[mid]);
            }
            else{
                if(!(m & 1)) return (all[mid] + all[mid-1]) / 2.;
                else return double(all[mid]);
            }
        }
    }
};