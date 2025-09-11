#include<iostream>
using namespace std;

// topic: linked list + fast-slow pointer
// time-complexity: O(n)
// space-complexity: O(1)

struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val)
    {
        data = val;
        next = nullptr;
    }
};

bool hasCycle(ListNode *head)
{
    if (head == nullptr)
    {
        return false;
    }
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;
    while (fastPtr && fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
        if (fastPtr == slowPtr)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        ListNode *newNode = new ListNode(val);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    if(hasCycle(head)){
        cout << "Cycle detected." << endl;
    }
    else{
        cout << "No cycle found." << endl;
    }
}