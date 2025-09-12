#include <iostream>
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

ListNode *detectCycle(ListNode *head)
{
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            break;
        }
    }
    if (!fast || !fast->next)
    {
        return nullptr;
    }
    ListNode *ptr = head;
    while (ptr != slow)
    {
        ptr = ptr->next;
        slow = slow->next;
    }
    return ptr;
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
    if (detectCycle(head))
    {
        cout << "Cycle detected." << endl;
    }
    else
    {
        cout << "No cycle found." << endl;
    }
}