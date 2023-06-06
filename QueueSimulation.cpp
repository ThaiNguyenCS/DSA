#include <iostream>

using namespace std;

class Queue
{
private:
    int rear;
    int front;
    int arr[5];
    int itemCount;
public: 
    Queue()
    {
        itemCount = 0; 
        rear = -1;
        front = -1;
        for(int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isFull()
    {
        if((rear + 1) % 5 == front)  // modified
            return true;
        else 
            return false;
    }

    bool isEmpty()
    {
        if(rear == -1 && front == -1)
            return true;
        else    
            return false;
    }

    void enqueue(int value)
    {
        if(isFull())
        {
            cout << "Queue is Full!" << endl;
        }
        else if(isEmpty())
        {
            rear = 0;
            front = 0;
            arr[rear] = value;
            itemCount++;
        }
        else 
        {
            rear = (rear + 1)%5;    // modified
            arr[rear] = value;
            itemCount++;
        }
    }

    int dequeue()
    {
        int x;
        if(isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return 0;
        }
        else if(front == rear)
        {
            x = arr[front];
            arr[front] = 0;
            front = -1;
            rear = -1;
            itemCount--;
            return x;
        }
        else
        {
            x = arr[front];
            arr[front] = 0;
            front = (front  + 1)%5;
            itemCount--;
            return x;
        }
    }
    
    int count()
    {
        return itemCount;
    }

    void clearScreen()
    {
        system("cls");
    }

    void display()
    {
        for(int i = 0; i < 5; i++)
        {
            cout << arr[i] << endl;
        }
    }

    void frontPrint()
    {
        cout << "Front = " << front << endl;
    }

    void rearPrint()
    {
        cout << "Rear = " << rear << endl;
    }
};

int main()
{
    int option;
    int value;
    Queue test;
    do
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Is Full?" << endl;
        cout << "4. Is Empty?" << endl;
        cout << "5. Count" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "7. Display all the items" << endl;
        cout << "8. Print Front Location" << endl;
        cout << "9. Print Rear Location" << endl;
        cin >> option;

        switch(option)
        {
            case 0: 
                break;
            case 1: 
            {
                cout << "Enter a value to a queue: ";
                cin >> value;
                test.enqueue(value);
                break;
            }
            case 2:
            {
                cout << "Dequeued Value: " << test.dequeue() << endl;
                break;
            }
            case 3:
            {
                if(test.isFull())
                    cout << "Queue is Full!" << endl;
                else
                    cout << "Queue is not Full!" << endl;
                break;
            }
            case 4: 
            {
                if(test.isEmpty())
                    cout << "Queue is empty!" << endl;
                else 
                    cout << "Queue is not empty!" << endl;
                break;
            }
            case 5:
            {
                cout << "Count of Items in Queue is: " << test.count() << endl; 
                break;
            }
            case 6:
            {
                test.clearScreen();
                break;
            }
            case 7: 
            {
                test.display();
                break;
            }
            case 8:
            {
                test.frontPrint();
                break;
            }
            case 9:
            {
                test.rearPrint();
            }
            default:
            {
                cout << "Please enter a proper number!" << endl;
                break;
            }
        }
    }  
    while(option != 0);
    
    return 0;

}