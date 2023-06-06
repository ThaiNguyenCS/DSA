#include <iostream>
using namespace std;

int main()
{
    int arr[] = {6,4,7,9,3,2,67,8,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    // Phan nay tu lam nhung O(n^3) lan
    // for(int i = 1; i < size; i++)
    // {
    //     int x = arr[i]; // Pick next element
    //     for(int j = 0; j < i; j++)
    //     {
    //         if(x > arr[j])
    //             continue;
    //         else
    //         {
    //             for(int k = i; k > j; k--)
    //             {
    //                 arr[k] = arr[k-1];
    //             }
    //             arr[j] = x;
    //             break;
    //         }
    //     }
    // }
    // Optimized one with O(n^2)
    
    for(int i = 1; i < size; i++)
    {
        int x = arr[i]; // Pick next element
        int j = i-1;
        while(j >= 0 && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }

    for(int i = 0; i  < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}