#include <iostream>

using namespace std;

void bubbleSort(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void swap(int&a, int&b)
{
    int temp = a;
    a = b;
    b = temp;
}

void display(int *arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {7,4,3,14,8,23,9,1,423,75,123,72};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    display(arr, size);
    return 0;
}