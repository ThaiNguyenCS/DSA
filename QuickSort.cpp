#include <iostream>

using namespace std;
void swap(int &a, int &b);

int partition(int arr[], int b, int e)
{
    int pivot = arr[e]; // Pick the last element as a pivot
    int pIndex = b; 
    for(int i = b; i < e; i++)
    {
        if(arr[i] <= pivot) // Ascending Sort
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[e]);
    return pIndex;
}

void QuickSort(int arr[], int b, int e)
{
    if(b < e)
    {
        int p = partition(arr,b,e); 
        QuickSort(arr, b, p-1);
        QuickSort(arr, p+1, e);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int arr[] = {3,7,8,334,3,7,9};
    QuickSort(arr, 0, 6);
    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}