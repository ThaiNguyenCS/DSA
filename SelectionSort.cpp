#include <iostream>

using namespace std;

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
        
    }
    cout << "\n";
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int arr[] = {5,7,8,12,76,71,123,7,2,6,9,4}; // 12 elements
    int size = 12;
    for(int i = 0; i < size-1; i++)
    {
        int min = i; // Ascending Sorting
        for(int j = i+1; j < size; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        if(min != i)
        {
            swap(arr[i], arr[min]);
        }
        display(arr, size);
    }
    return 0;
}