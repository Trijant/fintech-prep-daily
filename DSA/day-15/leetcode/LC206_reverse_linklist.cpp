#include<iostream>
using namespace std;

// Topic: linked list
// time-complexity:O(n)
// space-complexity:O(1)
struct ListNode
{
    int data;
    ListNode *next;
    ListNode(int val){
        data = val;
        next = nullptr;
    }
};


ListNode *reverseList(ListNode *head)
{
    ListNode *prevNode = nullptr;
    ListNode *nextNode = nullptr;
    while (head != nullptr)
    {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode;
}

int main(){
    int size;
    cout << "Enter size: ";
    cin >> size;
    ListNode *head = nullptr;
    ListNode *tail= nullptr;
    for (int i = 0; i < size; i++)
    {
        int val;
        cin >> val;
        ListNode *newNode=new ListNode(val);
        if (head==nullptr)
        {
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
        
    }
    head = reverseList(head);
    cout << "Reversed linked list: " << endl;
    ListNode *curNode = head;
    while (curNode!=nullptr)
    {
        cout << curNode->data << " ";
        curNode = curNode->next;
    }
    
}