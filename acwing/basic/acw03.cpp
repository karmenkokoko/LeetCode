#include <iostream>

using namespace std;

const int N = 100010;

int n;
int arr[N];
int temp[N];


void mergesort(int arr[], int l, int r)
{
    if(l >= r) return ;
    int mid = (l + r) >> 1;
    mergesort(arr, l, mid);
    mergesort(arr, mid+1, r);
    int i = l, j = mid + 1;
    int k = 0;

    while(i <= mid && j <= r)
    {
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
        
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];
    
    for(int i = l, k = 0; i <= r; i++, k++) arr[i] = temp[k];
}


int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergesort(arr, 0, n-1);
    
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}