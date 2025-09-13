#include<iostream>
using namespace std;

// topic: doubly linkedlist
// time-complexity: O(n)
// space-complexity: O(n)

struct Node
{
    int val;
    Node *prev;
    Node *next;
    Node(int val)
    {
        this->val = val;
        prev = nullptr;
        next = nullptr;
    }
};
class MyLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    MyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~MyLinkedList(){
        Node *ptr = head;
        while (ptr)
        {
            Node *next = ptr->next;
            delete ptr;
            ptr = next;
        }
        head = tail = nullptr;
    }

    Node *getNode(int index)
    {
        if (index > (size >> 1))
        {
            Node *ptr = tail;
            int curIdx = size - 1;
            while (ptr)
            {
                if (index == curIdx)
                {
                    return ptr;
                }
                ptr = ptr->prev;
                curIdx--;
            }
        }
        else
        {
            Node *ptr = head;
            int curIdx = 0;
            while (ptr)
            {
                if (curIdx == index)
                {
                    return ptr;
                }
                ptr = ptr->next;
                curIdx++;
            }
        }
        return nullptr;
    }
    int get(int index)
    {
        if (index >= size || index < 0)
        {
            return -1;
        }
        Node *ptr = getNode(index);
        if (ptr)
        {
            return ptr->val;
        }
        return -1;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head)
        {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        else
        {
            head = tail = newNode;
        }
        size++;
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail)
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        else
        {
            head = tail = newNode;
        }
        size++;
    }
    void addAtIndex(int index, int val)
    {
        if (index > size || index < 0)
        {
            return;
        }
        else if (index == size)
        {
            addAtTail(val);
        }
        else if (index == 0)
        {
            addAtHead(val);
        }
        else
        {
            Node *newNode = new Node(val);
            Node *ptr = getNode(index);
            ptr->prev->next = newNode;
            newNode->prev = ptr->prev;
            ptr->prev = newNode;
            newNode->next = ptr;
            size++;
        }
    }

    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete head;
            head = tail = nullptr;
        }
        else if (index == 0)
        {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        else if (index == size - 1)
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        else
        {
            Node *ptr = getNode(index);
            ptr->next->prev = ptr->prev;
            ptr->prev->next = ptr->next;
            delete ptr;
        }
        size--;
    }
};

int main(){
    cout << "Instructions: " << endl;
    cout << "====================================" << endl;
    cout << "ATH <val>: add to head" << endl;
    cout << "ATT <val>: add to tail" << endl;
    cout << "ATI <index> <val>: add to index" << endl;
    cout << "GT <index>: get" << endl;
    cout << "DI <index>: delete index" << endl;
    cout << "exit: exit from code" << endl;
    cout << "====================================" << endl;
    MyLinkedList *dll = new MyLinkedList();
    while (true)
    {
        string s;
        cin >> s;
        if (s=="ATH")
        {
            int val;
            cin >> val;
            dll->addAtHead(val);
        }
        else if (s=="ATT")
        {
            int val;
            cin >> val;
            dll->addAtTail(val);
        }
        else if (s=="ATI")
        {
            int val, index;
            cin >> index;
            cin >> val;
            dll->addAtIndex(index, val);
        }
        else if(s=="GT"){
            int index;
            cin >> index;
            cout<<"val:"<<dll->get(index)<<endl;
        }
        else if(s=="DI"){
            int index;
            cin >> index;
            dll->deleteAtIndex(index);
        }
        else if(s=="exit"){
            break;
        }
        else{
            cout << "Invalid instruction" << endl;
        }
        
        
        
    }
    
}