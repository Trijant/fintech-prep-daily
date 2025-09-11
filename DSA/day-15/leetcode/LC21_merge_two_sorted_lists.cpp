#include<iostream>
using namespace std;

// topic: linked list
// time-complexity: O(n+m)
// spcae-complexity: O(1)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int data)
    {
        val = data;
        next = nullptr;
    }
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == nullptr)
    {
        return list2;
    }
    else if (list2 == nullptr)
    {
        return list1;
    }
    ListNode *head = nullptr;
    ListNode *mergedList = nullptr;
    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            if (mergedList == nullptr)
            {
                head = mergedList = list1;
            }
            else
            {
                mergedList->next = list1;
                mergedList = mergedList->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (mergedList == nullptr)
            {
                head = mergedList = list2;
            }
            else
            {
                mergedList->next = list2;
                mergedList = mergedList->next;
            }
            list2 = list2->next;
        }
    }
    if (list1 != nullptr)
    {
        mergedList->next = list1;
    }
    else if (list2 != nullptr)
    {
        mergedList->next = list2;
    }
    return head;
}

int main()
{
    int size1,size2;
    cout << "Enter size of list1: ";
    cin >> size1;
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    for (int i = 0; i < size1; i++)
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
    cout << "Enter size of list2: ";
    cin >> size2;
    ListNode *head2 = nullptr;
    ListNode *tail2 = nullptr;
    for (int i = 0; i < size2; i++)
    {
        int val;
        cin >> val;
        ListNode *newNode = new ListNode(val);
        cout << newNode->val << endl;
        if (head2 == nullptr)
        {
            head2 = tail2 = newNode;
        }
        else
        {
            tail2->next = newNode;
            tail2 = newNode;
        }
    }
    head = mergeTwoLists(head,head2);
    cout << "merged linked list: " << endl;
    ListNode *curNode = head;
    while (curNode != nullptr)
    {
        cout << curNode->val << " ";
        curNode = curNode->next;
    }
}