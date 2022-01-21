#include <iostream>

using namespace std;

const int N = 100010;

int n, q;
int arr[N];


int main()
{
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while(q--)
    {
        int x ;
        cin >> x;

        int l = 0, r = n-1;
        
        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(x <= arr[mid]) r = mid;
            else l = mid + 1;
        }
        // 边界是l
        if(arr[l] != x) cout << "-1 -1" << endl;
        else{
            cout << l << " ";
            l = 0, r = n-1;
            
            while(l < r)
            {
                int mid = (l + r + 1) >> 1;
                if(x >= arr[mid]) l = mid;
                else r = mid - 1;
            }
            cout << l << endl;
        }

    }
    return 0;
}