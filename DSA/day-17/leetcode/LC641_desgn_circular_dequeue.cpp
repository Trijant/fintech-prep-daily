#include<iostream>
using namespace std;

// topic: circular dequeue + linked list
// time-complexity: O(1)
// space-complexity: O(n)

struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
    Node(int val, Node *next, Node *prev)
    {
        this->val = val;
        this->next = next;
        this->prev = prev;
    }
};

class MyCircularDeque
{
    Node *front;
    Node *rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k)
    {
        size = 0;
        capacity = k;
        front = rear = nullptr;
    }
    ~MyCircularDeque()
    {
        while (front)
        {
            deleteFront();
        }
    }
    void insertNodeBetweenFrontAndRear(Node *newNode)
    {
        if (size == 0)
        {
            newNode->next = newNode;
            newNode->prev = newNode;
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            newNode->prev = rear;
            rear->next = newNode;
            front->prev = newNode;
        }
        size++;
    }

    bool insertFront(int value)
    {
        if (size == capacity)
        {
            return false;
        }
        Node *newNode = new Node(value);
        insertNodeBetweenFrontAndRear(newNode);
        front = newNode;
        return true;
    }

    bool insertLast(int value)
    {
        if (size == capacity)
        {
            return false;
        }
        Node *newNode = new Node(value);
        insertNodeBetweenFrontAndRear(newNode);
        rear = newNode;
        return true;
    }

    void removeNode(Node *ptr)
    {
        if (size == 1)
        {
            delete ptr;
            front = rear = nullptr;
        }
        else
        {
            Node *prevNode = ptr->prev;
            Node *nextNode = ptr->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
            delete ptr;
        }
        size--;
    }

    bool deleteFront()
    {
        if (size <= 0)
        {
            return false;
        }
        Node *curNode = front;
        front = front->next;
        removeNode(curNode);
        return true;
    }

    bool deleteLast()
    {
        if (size <= 0)
        {
            return false;
        }
        Node *curNode = rear;
        rear = rear->prev;
        removeNode(curNode);
        return true;
    }

    int getFront()
    {
        return front ? front->val : -1;
    }

    int getRear()
    {
        return rear ? rear->val : -1;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull()
    {
        return size == capacity;
    }
};

int main()
{
    int size;
    cout << "Enter size of queue:";
    cin >> size;
    cout << "Instructions: " << endl;
    cout << "insertfront val: for inserting at front" << endl;
    cout << "insertrear val: for inserting at rear" << endl;
    cout << "deletefront: for deletion at front" << endl;
    cout << "deleterear: for deletion at rear" << endl;
    cout << "isempty: for checking if queue empty" << endl;
    cout << "isfull: for checking if queue is full" << endl;
    cout << "rear:getting value of rear" << endl;
    cout << "front:getting value of front" << endl;
    cout << "exit: exit the code" << endl;
    MyCircularDeque *q = new MyCircularDeque(size);
    while (true)
    {
        string i;
        cin >> i;
        if (i == "exit")
        {
            break;
        }
        else if (i == "insertfront")
        {
            int val;
            cin >> val;
            if (q->insertFront(val))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (i == "insertrear")
        {
            int val;
            cin >> val;
            if (q->insertLast(val))
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (i == "deletefront")
        {
            if (q->deleteFront())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (i == "deleterear")
        {
            if (q->deleteLast())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (i == "isempty")
        {
            if (q->isEmpty())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }

        else if (i == "isfull")
        {
            if (q->isFull())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
        }
        else if (i == "front")
        {
            cout << "front: " << q->getFront() << endl;
        }
        else if (i == "rear")
        {
            cout << "rear: " << q->getRear() << endl;
        }
        else
        {
            cout << "Invalid instruction!" << endl;
        }
    }
}