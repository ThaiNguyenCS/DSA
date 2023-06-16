#include <iostream>
#include <math.h>
#include <limits.h>
using namespace std;


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
class MinHeap
{
public:
    int capacity;
    int size;
    int *arr;

    MinHeap(int cap) : capacity(cap), size(0), arr(new int[cap]) {}
    void linearSeach(int val)
    {
        for(int i = 0; i < size; i++)
        {
            if(arr[i] == val)
            {
                cout << "Node with value " << val << " exists!\n";
                break;
            }
        }
        cout << "Node with value " << val << "does not exist!\n";
    }
    ~MinHeap()
    {
        delete [] arr;
    }

    void print()
    {
        for(int i =0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    int height()
    {
        if(size == 0)
            return -1;
        return (int)log2(size);
    }

    int parentIdx(int i)
    {
        return (int)((i-1)/2);
    }

    int left(int i)
    {
        if(2*i + 1 < size)
            return 2*i + 1;
    }

    int right(int i)
    {
        if(2*i + 2 < size)
            return 2*i + 2;
    }

    void minHeapify(int i)
    {
        int lChild = left(i);
        int rChild = right(i);
        int smallest = i;
        if(lChild < size && arr[lChild] < arr[i])
            smallest = lChild;
        if(rChild < size && arr[rChild] < arr[smallest])
            smallest = rChild;
        if(smallest != i)
        {
            swap(arr[smallest], arr[i]);
            minHeapify(smallest);
        }
    }

    void extractMin() // Delete Root 
    {
        if(size == 0)
        {
            cout << "Heap is empty!\n";
        }
        else if(size == 1)
        {
            size--;
        }
        else
        {
            arr[0] = arr[size-1];
            size--;
            minHeapify(0);
        }
    }

    void decreaseNode(int i) //10
    {
        arr[i] = INT_MIN;
        while(i != 0 && arr[parentIdx(i)] > arr[i])
        {
            swap(arr[parentIdx(i)], arr[i]);
            i = parentIdx(i);
        }
    }   
    void deleteNode(int idx)
    {
        if(idx < size && idx >= 0)
        {
            decreaseNode(idx);
            extractMin();
        }
    }

    void insert(int val)
    {
        if(size == capacity)
        {
            cout << "Heap Overflow!\n";
            return;
        }
        else
        {
            size++;
            int i = size - 1;
            arr[i] = val;
            while(i != 0 && arr[parentIdx(i)] > arr[i])
            {
                swap(arr[i], arr[parentIdx(i)]);
                i = parentIdx(i);
            }
        }
    }

    int currentSize()
    {
        return size;
    }

};

int main()
{
    int option;
    int cap; 
    cout << "Enter the capacity of the heap: ";
    cin >> cap;
    MinHeap heap1(cap);
    do
    {
        cout << "1.Insert Node\n2.Find Height of the heap\n3.Extract Min\n4.Search\n5.Print\n6.Find Size\n7.Delete\n";
        cout << "Option: ";
        cin >> option;
        switch(option)
        {
            case 1: 
            {
                cout << "Enter value you want to insert: ";
                int val;
                cin >> val;
                heap1.insert(val);
                break;
            }
            case 2:
            {
                cout << "Height of the Heap is: " << heap1.height() << endl;
                break;
            }
            case 3:
            {
                heap1.extractMin();
                cout << "Extract Min Done!\n";
                break;
            }
            case 4:
            {
                cout << "Enter value to search: ";
                int val;
                cin >> val;
                heap1.linearSeach(val);
                break;
            }
            case 5:
            {
                heap1.print();
                cout << "\n";
                break;
            }
            case 6:
            {
                cout << "Size of the Heap: " << heap1.currentSize() << endl;
                break; 
            }
            case 7:
            {
                cout << "Enter index need deleting: ";
                int idx;
                cin >> idx;
                heap1.deleteNode(idx);
                break;
            }
        }
    }while(option != 0);
    return 0;
}