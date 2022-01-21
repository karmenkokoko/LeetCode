// 求逆序对

#include <iostream>

using namespace std;

const int N = 100010;
typedef long long LL;
// 很可能会爆Int

int n;
int arr[N];
int temp[N];

LL mergesort(int arr[], int l, int r)
{
    if(l >= r) return 0;

    int mid = (l + r) >> 1;
    LL res = mergesort(arr, l, mid) + mergesort(arr, mid+1, r);
    
    int i = l, j = mid+1;
    int k = 0;
    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            res += mid - i + 1;
            temp[k++] = arr[j++];
        } 
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];

    for(i = l, k = 0; i <= r; i++, k++) arr[i] = temp[k];
    return res;
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << mergesort(arr, 0, n-1) << endl;

    return 0;
}