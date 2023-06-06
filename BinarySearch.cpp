#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int value)
{
    while(left <= right)
    {
        int mid = (left+right)/2;
        if(arr[mid] == value)
            return mid;
        else
        {
            if(value > arr[mid])
            {
                left = mid + 1;
                cout << "left " << left << endl;
            }
            else
            {
                right = mid - 1;
                cout << "right " << right << endl;
            }
        }
    }
    return -1;    
}

int main()
{
    int sortedList[] = {1,5,7,8,9,34,56,68,92,102};
    int value;
    cout << "Enter finding value: ";
    cin >> value;
    cout << binarySearch(sortedList, 0, 9, value);

    return 0;

}