#include <iostream>

using namespace std;

const int N = 100010;

int n;
int arr[N];

void quick_sort(int arr[], int l, int r)
{
    if(l >= r) return;

    int i = l-1, j = r+1;
    int mid = (l + r) >> 1;
    while(i < j)
    {
        // 这里等于号不能加
        do i++; while(arr[mid] > arr[i]);
        do j--; while(arr[mid] < arr[j]);
        // if (i<j)
        if(i < j) swap(arr[i], arr[j]);
    } 
    quick_sort(arr, l, j);
    quick_sort(arr, j+1, r);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}