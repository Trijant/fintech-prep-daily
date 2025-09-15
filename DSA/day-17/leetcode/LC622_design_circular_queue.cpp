#include<iostream>
using namespace std;

// topic: circular queue + linked list
// time-complexity: O(1)
// space-complexity: O(n)

struct Node
{
    int val;
    Node *next;
    Node()
    {
        next = nullptr;
    }
    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

class MyCircularQueue
{
    Node *front;
    Node *rear;
    int size;
    int capacity;

public:
    MyCircularQueue(int k)
    {
        capacity = k;
        size = 0;
        front = rear = nullptr;
    }
    ~MyCircularQueue()
    {
        while (front)
        {
            deQueue();
        }
    }

    bool enQueue(int value)
    {
        if (size == capacity)
        {
            return false;
        }
        Node *newNode = new Node(value);
        if (size == 0)
        {
            newNode->next = newNode;
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        return true;
    }

    bool deQueue()
    {
        if (size == 0)
        {
            return false;
        }
        if (size == 1)
        {
            delete front;
            front = rear = nullptr;
        }
        else
        {
            front = front->next;
            delete rear->next;
            rear->next = front;
        }
        size--;
        return true;
    }

    int Front()
    {
        return front ? front->val : -1;
    }

    int Rear()
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

int main(){
    int size;
    cout << "Enter size of queue:";
    cin >> size;
    cout << "Instructions: " << endl;
    cout << "enq val: for inserting" << endl;
    cout << "deq: for deletion" << endl;
    cout << "isempty: for checking if queue empty" << endl;
    cout << "isfull: for checking if queue is full" << endl;
    cout << "rear:getting value of rear" << endl;
    cout << "front:getting value of front" << endl;
    cout << "exit: exit the code" << endl;
    MyCircularQueue *q = new MyCircularQueue(size);
    while (true)
    {
        string i;
        cin >> i;
        if (i=="exit")
        {
            break;
        }
        else if (i=="enq")
        {
            int val;
            cin >> val;
            if(q->enQueue(val)){
                cout << "true"<<endl;
            }else{
                cout << "false"<<endl;
            }
        }
        else if(i=="deq"){
            if(q->deQueue()){
                cout << "true" << endl;
            }else{
                cout << "false" << endl;
            }
        }
        else if (i=="isempty")
        {
            if(q->isEmpty()){
                cout << "true" << endl;
            }
            else{
                cout << "false" << endl;
            }
        }
        
        else if (i=="isfull")
        {
            if (q->isFull())
            {
                cout << "true" << endl;
            }
            else{
                cout << "false" << endl;
            }
        }
        else if (i=="front")
        {
            cout <<"front: "<< q->Front()<<endl;
        }
        else if (i=="rear")
        {
            cout << "rear: " << q->Rear() << endl;
        }
        else{
            cout << "Invalid instruction!" << endl;
        }
    }
}