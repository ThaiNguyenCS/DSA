#include <iostream>

using namespace std;

class Stack
{
private: 
    int top;
    int arr[5];
public: 
    Stack()
    {
        top = -1;
        for(int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }

    bool isEmpty()
    {
        if(top ==  -1) 
            return true;
        else 
            return false;
    }
    bool isFull()
    {
        if(top == 4)
        {
            return true;
        }
        else 
            return false;
    }

    void push(int value)
    {
        if(isFull())
        {
            cout << "Stack overflow!" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack underflow!" << endl;
        }
        else
        {
            int popValue = arr[top];
            arr[top] = 0;
            top--;
            return popValue;
        }
    }
};

int main()
{
    
    return 0;
}
