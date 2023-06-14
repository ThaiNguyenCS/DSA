#include <iostream>

using namespace std;
#define SPACE 5
class Node;
class BST;
void levelPrint(Node *r, int level);
int height(Node*);
Node* findMinRight(Node *r);
class Node
{
public:
    Node *left;
    Node *right;
    int data;
    Node(int d) : data(d), right(nullptr), left(nullptr) {}
    Node(): right(nullptr), left(nullptr) {} 
};

class BST
{
public:
    Node *root;
    BST() : root(nullptr) {}
    bool isEmpty();
    void insert(int v); // Insertion Using Iteration
    Node* insert(Node* , int); // Insertion Using Recursive
    Node* insertAVL(Node*, int);
    Node* deleteAVL(Node*, int);
    void preOrder(Node *a) const;
    void postOrder(Node *a) const;
    void inOrder(Node *a) const;
    void print2D(Node*,int) const;
    Node* iterativeSearch(int) const;
    Node* deleteNode(Node*, int);
};

int findBF(Node *r)
{
    return height(r->left) - height(r->right);
}

Node* rightRotate(Node *r)
{
    Node *sec = r->left;
    r->left = sec->right;
    sec->right = r;
    return sec;
}

Node* leftRotate(Node *r)
{
    Node *sec = r->right;
    r->right = sec->left;
    sec->left = r;
    return sec;
}

Node* BST::deleteAVL(Node *r, int v)
{
    if(r == nullptr)
    {
        cout << "No Node with value " << v << " exist\n";
        return r;
    }
    else if(v < r->data)
    {
        r->left = deleteAVL(r->left, v);
    }
    else if(v > r->data)
    {
        r->right = deleteAVL(r->right, v);
    }
    else // v == r->data
    {
        if(r->left == nullptr) // node has right child or no child
        {
            Node *temp = r->right; // nullptr or 1 node
            delete r;
            return temp;
        }
        else if(r->right == nullptr) // node has only left child
        {
            Node *temp = r->left;
            delete r;
            return temp;
        }
        else // node has both right and left children
        {
            Node *temp = findMinRight(r->right);
            r->data = temp->data;
            r->right = deleteAVL(r->right, temp->data);
            return r;
        }
    }
    int BF = findBF(r);
    cout << "BF of " << r->data << " is: " << BF << endl;
    if(BF > 1 && findBF(r->left) >= 0) // Left Left case
    {
        return rightRotate(r);
    }
    else if(BF < -1 && findBF(r->right) <= 0) // Right Right case
    {
        return leftRotate(r);
    }
    else if(BF > 1 && findBF(r->left) < 0) // Left Right case
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    else if(BF < -1 && findBF(r->right) > 0) // Right Left case
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }
    return r;
}
Node* BST::insertAVL(Node *r, int v)
{   
    if(r == nullptr)
    {
        r = new Node(v);
        return r;
    }
    else
    {
        if(v > r->data)
        {
            r->right = insertAVL(r->right, v);
        }
        else if(v < r->data)
        {
            r->left = insertAVL(r->left, v);
        }
        else
        {
            cout << "Node with value " << v << " has existed!\n";
            return r;
        }
    }
    int BF = findBF(r);
    cout << "BF of " << r->data << " is: " << BF << endl;
    if(BF > 1 && r->left->data > v) // Left Left case
    {
        return rightRotate(r);
    }
    else if(BF < -1 && r->right->data < v) // Right Right case
    {
        return leftRotate(r);
    }
    else if(BF > 1 && r->left->data < v)
    {
        r->left = leftRotate(r->left);
        return rightRotate(r);
    }
    else if(BF < -1 && r->right->data > v)
    {
        r->right = rightRotate(r->right);
        return leftRotate(r);
    }

    return r;
}

Node* BST::insert(Node *r, int v)
{
    if(r == nullptr)
    {
        r = new Node(v);
        return r;
    }
    else
    {
        if(v < r->data)
        {
            r->left = insert(r->left, v);
        }
        else if(v > r->data)
        {
            r->right = insert(r->right, v);
        }
        else
        {
            cout << "Node with value " << v << " has existed!\n";
            return nullptr;
        }
    }
    return r;
}

Node* findMinRight(Node *r)
{
    while(r->left != nullptr)
    {
        r = r->left;
    }
    return r;
}

// Delete a particular Node with value v.
Node* BST::deleteNode(Node *r, int v)
{
    if(r == nullptr)
        return r;
    else if(r->data > v)
    {
        r->left = deleteNode(r->left, v);
    }
    else if(r->data < v)
    {
        r->right = deleteNode(r->right, v);
    }
    else if(r->data == v)
    {
        if(r->left == nullptr) // Node need deleting has 1 right child or no children.
        {
            Node* temp = r->right;
            delete r;
            return temp;
        }
        else if(r->right == nullptr)
        {
            Node *temp = r->left;
            delete r;
            return temp;
        }
        else
        {
            Node *temp = findMinRight(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }
    }
    return r;
}

int height(Node *r) 
{
    if(r == nullptr)
        return -1;
    else
    {
        int lHeight = height(r->left);
        int rHeight = height(r->right);
        if(lHeight > rHeight)
            return lHeight + 1;
        else
            return rHeight + 1;
    }
}  

void BFS(Node *r)
{
    int h = height(r);
    for(int i = 0; i <= h; i++)
    {
        levelPrint(r, i);
    }
}

void levelPrint(Node *r, int level)
{
    if(r == nullptr)
        return;
    else if(level == 0)
    {
        cout << r->data << " ";
    }
    else
    {
        levelPrint(r->left, level-1);
        levelPrint(r->right, level-1);
    }

}

Node* BST::iterativeSearch(int v) const
{
    if(root == nullptr)
    {
        cout << "No Node Exist!\n";
        return nullptr;
    }
    else
    {
        Node *r= root;
        while(r!= nullptr)
        {
            if(v == r->data)
            {
                return r;
            }
            else if(v > r->data)
            {
                r= r->right;
            }
            else if(v < r->data)
            {
                r= r->left;
            }
        }
        cout << "No Node with value " << v << " exists!\n";
        return nullptr;
    }
}

void deleteNode(Node *a) 
{
    if(a == nullptr)
        return;
    else
    {
        deleteNode(a->left);
        deleteNode(a->right);
        delete a;
        a = nullptr;
    }
}

void BST::postOrder(Node *a) const
{
    if(a == nullptr)
        return;
    else
    {
        postOrder(a->left);
        postOrder(a->right);
        cout << a->data << " ";
    }
}

void BST::inOrder(Node *a) const
{
    if(a == nullptr)
        return;
    else
    {
        inOrder(a->left);
        cout << a->data << " ";
        inOrder(a->right);
    }
}

void BST::preOrder(Node *a) const
{   
    if(a == nullptr)
        return;
    else
    {
        cout << a->data << " ";
        preOrder(a->left);
        preOrder(a->right);
    }
}

void BST::print2D(Node *a, int space) const
{
    if (a == NULL) 
        return;
    space += SPACE; 
    print2D(a->right, space); // Process right child first 3 
    for (int i = SPACE; i < space; i++) // 5 
        cout << " "; // 5.1  
    cout << a->data  << "\n"; // 6
    print2D(a->left, space); // Process left child  7
}

void BST::insert(int v) // Using Iteration
{
    if(isEmpty())
    {
        root = new Node(v);
    }
    else 
    {
        Node *traverse = root;
        while(true)
        {
            if(v == traverse->data)
            {
                cout << v << " has existed!";
                break;
            }
            else if(v < traverse->data && traverse->left == nullptr)
            {
                traverse->left = new Node(v);
                break;
            }
            else if(v > traverse->data && traverse->right == nullptr)
            {
                traverse->right = new Node(v);
                break;
            }
            else if(v < traverse->data)
            {
                traverse = traverse->left;
            }
            else if(v > traverse->data)
            {
                traverse = traverse->right;
            } 
        }
    }
}

bool BST::isEmpty()
{
    if(root == nullptr)
        return true;
    else  
        return false;
}


int main()
{
    int option;
    BST tree1;
    do
    {
        cout << "Options:\n" << "1. Is Empty?\n2. Insert Using Iteration\n3. Post order\n4. Pre Order\n5. In Order\n"
        "6. Iterative Search\n7. Find Height\n8. Print\n9. Print BFS\n10. Delete Node\n11. Insert Using Recursive\n12. Insert AVL\n"
        "13. Delete AVL\n";
        cin >> option;
        switch(option)
        {
            case 1:
            {
                if(tree1.isEmpty())
                    cout << "Empty!" << endl;
                else
                    cout << "NO!" << endl;
                break;
            }
            case 2:
            {
                cout << "Enter a value: ";
                int value;
                cin >> value;
                tree1.insert(value);
                break;
            }
            case 3:
            {
                tree1.postOrder(tree1.root);
                break;
            }
            case 4:
            {
                tree1.preOrder(tree1.root);
                break;
            }
            case 5:
            {
                tree1.inOrder(tree1.root);
                break;
            }
            case 6:
            {
                int a;
                cout << "Enter a value need searching: ";
                cin >> a;
                cout << tree1.iterativeSearch(a) << endl;
                break;
            }
            case 7:
            {
                cout << "Height = " << height(tree1.root) << endl;
                break;
            }
            case 8:
            {
                tree1.print2D(tree1.root, 0);
                break;
            }
            case 9:
            {
                BFS(tree1.root);
                break;
            }
            case 10:
            {
                cout << "Enter value to delete: ";
                int val;
                cin >> val;
                tree1.root = tree1.deleteNode(tree1.root, val);
                break;
            }
            case 11:
            {
                cout << "Enter a value: ";
                int val;
                cin >> val;
                tree1.root = tree1.insert(tree1.root, val);
                break;
            }
            case 12:
            {
                cout << "Enter a value: ";
                int val;
                cin >> val;
                tree1.root = tree1.insertAVL(tree1.root, val);
                break;
            }
            case 13:
            {
                cout << "Enter a value need deleting: ";
                int val;
                cin >> val;
                tree1.root = tree1.deleteAVL(tree1.root, val);
                break;
            }
            default:
                break;
        }  
    }while(option != -1 );
    deleteNode(tree1.root);
    return 0;
}