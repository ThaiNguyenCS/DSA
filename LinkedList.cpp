#include <iostream>

using namespace std;

class singlyNode
{
public:
    int data;
    singlyNode *next;
    singlyNode() : next(nullptr) {}
    singlyNode(int D) : data(D), next(nullptr) {}
};

class singlyLL
{
public:
    singlyNode *head;
    int count;
    singlyLL() : head(nullptr), count(0) {}
    bool isEmpty()
    {
        if(count == 0)
            return true;
        else 
            return false;
    }
    void append(int value)
    {
        if(this->isEmpty())
        {
            singlyNode *a = new singlyNode(value);
            head = a;
            count++;
        }
        else
        {
            singlyNode *traverse = head;
            while(traverse->next != nullptr)
            {
                traverse = traverse->next;
            }
            traverse->next = new singlyNode(value);
            count++;
        }
    }

    void prepend(int value)
    {
        if(this->isEmpty())
        {
            singlyNode *a = new singlyNode(value);
            head = a;
            count++;
        }
        else
        {
            singlyNode *temp = new singlyNode(value);
            temp->next = head;
            head = temp;
            count++;
        }
    }

    void search(int value)
    {
        if(this->isEmpty())
        {
            cout << "Node has value: " << value << " doesn't exist.";
        }
        else
        {
            singlyNode *traverse = head;
            int pos = -1;
            for(int i = 0; i < count; i++)
            {
                if(traverse->data == value)
                {
                    pos = i;
                    break;
                }
            }
            if(pos != -1)
            {
                cout << "Node with value " << value << " has been found at position " << pos << endl;
            }
            else
            {
                cout << "Node has value: " << value << " doesn't exist.";
            }

        }
    }
};

class doublyNode
{
public:
    int data;
    doublyNode *next;
    doublyNode *pre;
    doublyNode() : next(nullptr), pre(nullptr) {}
    doublyNode(int D) : data(D), pre(nullptr), next(nullptr) {}
};

class doublyLL
{
public:
    doublyNode *head;
    doublyLL() : head{nullptr} {}
    ~doublyLL()
    {
        while(head != nullptr)
        {
            doublyNode *cleaner = head;
            head = head->next;
            delete cleaner;
            cleaner = nullptr;
        }
        cout << "Clear!";
    }
    bool isEmpty()
    {
        if(head == nullptr)
            return true;
        else
            return false;
    }

    void append(int D)  
    {
        if(this->isEmpty())
        {   
            head = new doublyNode(D);
        }
        else
        {
            doublyNode *traverse = head;
            while(traverse->next != nullptr)
            {
                traverse = traverse->next;
            }
            doublyNode *temp = new doublyNode(D);
            traverse->next = temp;
            temp->pre = traverse;
        }
    }

    void prepend(int D)
    {
        if(this->isEmpty())
        {
            head = new doublyNode(D);
        }
        else
        {
            doublyNode *temp = new doublyNode(D);
            head->pre = temp;
            temp->next = head;
            head = temp;
        }
    }

    void display()
    {
        doublyNode *traverse = head;
        while(traverse != nullptr)
        {
            cout << traverse->data << " ";
            traverse = traverse->next;
        }
        cout << "\n";
        }
};

class CircularLL
{
public:
    singlyNode *head;
    CircularLL() : head(nullptr) {} 
    ~CircularLL()
    {
        if(head != nullptr)
        {
            singlyNode *cleaner = head->next;
            while(cleaner != head)
            {
                singlyNode *temp = cleaner;
                cleaner = cleaner->next;
                delete temp;
                temp = nullptr;
            }
            delete head;
            head = nullptr;
        }
    }
    bool isEmpty()
    {
        if(head == nullptr)
            return true;
        else
            return false;
    }

    void append(int D)
    {
        if(this->isEmpty())
        {
            head = new singlyNode(D);
            head->next = head;
        }
        else
        {
            singlyNode *temp = new singlyNode(D);
            singlyNode *traverse = head;
            while(traverse->next != head)
            {
                traverse = traverse->next;
            }
            temp->next = head;
            traverse->next = temp;
        }
    }

    void prepend(int D)
    {
        if(this->isEmpty())
        {
            head = new singlyNode(D);
            head->next = head;
        }
        else
        {
            singlyNode *temp = new singlyNode(D);
            singlyNode *traverse = head;
            while(traverse->next != head)
            {
                traverse = traverse->next;
            }
            temp->next = head;
            traverse->next = temp;
            head = temp; // Different from append

        }
    }

    void display()
    {
        singlyNode *traverse = head;
        if(traverse == nullptr)
        {
            cout << "No node exists" << endl;
        }
        else
        {
            do
            {
                cout << traverse->data << " ";
                traverse = traverse->next;
            }
            while(traverse != head);
        }
        cout << "\n";
    }

};
int main()
{
    CircularLL c1;
    c1.append(1);
    c1.display();
    c1.prepend(2);
    c1.display();
    c1.prepend(5);
    c1.display();
    c1.append(6);
    c1.display();

    return 0;
}