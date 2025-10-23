#include<bits/stdc++.h>
using namespace std;

// topic : min heap + linked list



 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution
{
private:
    struct cmp
    {
        bool operator()(ListNode *l1, ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int size = lists.size();
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto &l : lists)
        {
            if (l)
                pq.push(l);
        }
        if (pq.empty())
            return nullptr;
        ListNode *head = pq.top();
        ListNode *tail = head;
        pq.pop();
        if (tail->next)
            pq.push(tail->next);
        while (!pq.empty())
        {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if (tail->next)
                pq.push(tail->next);
        }
        return head;
    }
};

int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    vector<ListNode*>lists(size);
    for (int i = 0; i < size; i++)
    {
        int n;
        cout << "Enter size of current list: ";
        cin >> n;
        cout << "Enter elements: " << endl;
        ListNode *head=nullptr, *tail=nullptr;
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            ListNode * newNode=new ListNode(val);
            if(!head)
                head = tail = newNode;
            else{
                tail->next=newNode;
                tail = newNode;
            }
        }
        lists[i] = head;
    }
    Solution s;
    ListNode *m = s.mergeKLists(lists);
    ListNode *ptr = m;
    while(ptr){
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
}