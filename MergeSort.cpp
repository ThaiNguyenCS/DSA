#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i = l, j = m+1, k = l;
    int temp[50];
    while(i <= m && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++, k++;
        }
        else
        {
            temp[k] = arr[j];
            j++, k++;
        }
    }

    while(i <= m)
    {
        temp[k] = arr[i];
        i++, k++;
    }
    while(j <= r)
    {
        temp[k] = arr[j];
        j++, k++;
    }
    for(int x = l; x <= r; x++)
    {
        arr[x] = temp[x];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r) 
    {
        int m = (l+r)/2; 
        mergeSort(arr, l, m);  
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r);
    }
}

int main()
{
    int arr[] = {3,2,1};
    mergeSort(arr,0,2);
    for(int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}