#include <iostream>

using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next; //do doi tuong duoc tro toi la 1 Node nen ta su dung con tro co kieu Node
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class singlyLinkedList
{
public:
    Node *head;
    singlyLinkedList() // Constructor
    {
        head = NULL;
    }
    singlyLinkedList(Node *n)
    {
        head = n;
    }   
    Node* nodeExists(int k) // Hàm trả về con trỏ
    {
        Node* temp = NULL;
        Node* ptr = head;
        while(ptr != NULL)
        {
            if(ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;    
        }
        return temp;
    }

    void prependNode (Node *n)
    {
        if(nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value" << n->key << " . Append another node with different key value!" << endl;
        }
        else
        {
            if(head == NULL)
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else
            {
               n->next = head;
               head = n;
            }

        }
    }

    void appendNode (Node *n) // *n la node can append.
    {
        if(nodeExists(n->key) != NULL)
        {
            cout << "Node already exists with key value" << n->key << " . Append another node with different key value!" << endl;
        }
        else
        {
            if(head == NULL)
            {
                head = n;
                cout << "Node appended" << endl;
            }
            else
            {
                Node* ptr = head;
                while(ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node appended" << endl;
            }
        }
    }
    void insertNode(int k, Node* n) // k la key cua Node dung truoc Node can them
    {
        Node* ptr = nodeExists(k); // Node 2s
        if(ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
        }
        else
        {
            if(nodeExists(n->key) != NULL)
            {
                cout << "Node already exists with key value" << n->key << " . Insert another node with different key value!" << endl;
            }
            else
            {
                n->next = ptr->next; // Node 4 trỏ vào Node 3
                ptr->next = n; // Chưa hiểu vì sao có nó thể làm Node 2 trỏ tới Node 4 ????
                cout << "Node Inserted!" << endl;
            }
        }
    }
    void deleteNode(int k)
    {
        if(head == NULL)
        {
            cout << "Linked List is empty" << endl;
        }
        else if (head != NULL)
        {
            if(head->key == k)
            {
                head = head->next;
                cout << "Node Unlinked with key value: " << k << endl;
            }
            else
            {
                Node* temp = NULL;
                Node* previousPtr = head;
                Node* currentPtr = head->next;
                while(currentPtr != NULL)
                {
                    if(currentPtr->key == k)
                    {
                        temp = currentPtr;  // CurrentPtr sẽ là Node bị xóa
                        currentPtr = NULL;
                    }
                    else
                    {
                        currentPtr = currentPtr->next;
                        previousPtr = previousPtr->next;
                    }
                    if(temp != NULL)
                    {
                        previousPtr->next = temp->next;
                        cout << "Node Unlinked with key value: " << k << endl;
                    }
                    else
                    {
                        cout << "Node doesnot exist with key value: " << k << endl;
                    }
                }
            }
        }
    }
    void updateNode(int k, int d)
    {
        Node* ptr = nodeExists(k);
        if(ptr != NULL)
        {
            ptr->data = d;
            cout << "Node data updated successfully!" << endl;
        }
        else
        {
            cout << "Node doesn't exist" << endl;
        }
    }

    void printlist()
    {
        if(head == NULL)
        {
            cout << "No Nodes exist" << endl;
        }
        else
        {
            cout << "Singly Linked list values: ";
            Node* temp = head;
            while(temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << ") --> ";
                temp = temp->next; 
            }
        }
    }
};

int main()
{
    singlyLinkedList s;
    int option;
    int key1, k1, data1;
    do{
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;

    cin >> option;
    Node * n1 = new Node();
    //Node n1;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;

    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1);
      break;

    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;

      s.insertNode(k1, n1);
      break;

    case 4:

      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNode(k1);

      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNode(key1, data1);

      break;
    case 6:
      s.printlist();

      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

    return 0;
}