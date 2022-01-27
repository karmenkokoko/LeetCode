#include <iostream>

using namespace std;

const int N = 100010;
int n, k;
int arr[N];

int quick_sort(int arr[], int l, int r, int k)
{
    if(l >= r) return arr[l];

    int i = l-1, j = r+1;
    int mid = arr[(l+r) >> 1];

    while(i < j)
    {
        do i++; while(arr[i]<mid);
        do j--; while(arr[j]>mid);
        if(i<j) swap(arr[i], arr[j]);
    }
    if(j-l+1 >= k) return quick_sort(arr, l, j, k);
    else return quick_sort(arr, j+1, r, k - (j-l+1));
}

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << quick_sort(arr, 0, n-1, k) << endl;
    return 0;
}