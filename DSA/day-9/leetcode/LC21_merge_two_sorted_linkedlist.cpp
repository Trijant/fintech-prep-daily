#include<iostream>
using namespace std;

// Topic: linked list + recursion
// Time-complexity: O(n+m)
// Space-complexity: O(max(n,m))    ; recursive stack

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(nullptr){}
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
    if (list1->val < list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else
    {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}

int main(){
    int size1, size2;
    cout << "Enter size1: ";
    cin >> size1;
    cout << "Enter size2: ";
    cin >> size2;
    ListNode *l1_head=nullptr, *l2_head=nullptr,*l1_tail=nullptr,*l2_tail=nullptr;
    cout << "Enter elements of list1: " << endl;
    for (int i = 0; i < size1; i++)
    {
        int num;
        cin >> num;
        ListNode *currentNode = new ListNode(num);
        if (l1_head==nullptr)
        {
            l1_head = currentNode;
            l1_tail = currentNode;
        }
        else{
            l1_tail->next = currentNode;
            l1_tail = l1_tail->next;
        }
    }
    cout << "Enter elements of list2: " << endl;
    for (int i = 0; i < size2; i++)
    {
        int num;
        cin >> num;
        ListNode *currentNode = new ListNode(num);
        if (l2_head==nullptr)
        {
            l2_head = currentNode;
            l2_tail = currentNode;
        }
        else{
            l2_tail->next = currentNode;
            l2_tail = l2_tail->next;
        }
    }
    ListNode *sortedList = mergeTwoLists(l1_head, l2_head);
    while (sortedList!=nullptr)
    {
        cout << sortedList->val << " ";
        sortedList = sortedList->next;
    }
    
}