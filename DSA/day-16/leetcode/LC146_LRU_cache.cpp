#include<iostream>
#include<unordered_map>
using namespace std;

// topic : map + doubly linkedlist
// time-complexity: O(1)
// space-complexity:O(n)

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int k, int v)
    {
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};
class LRUCache
{
    Node *head = nullptr;
    Node *tail = nullptr;
    unordered_map<int, Node *> mp;
    int capacity;

public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key)
    {
        if (mp.count(key))
        {
            Node *ptr = mp[key];
            updateTailNode(ptr);
            return ptr->val;
        }
        return -1;
    }

    void updateTailNode(Node *currNode)
    {
        if (!head)
        {
            head = tail = currNode;
            return;
        }
        if (currNode == tail)
        { // already tail node
            return;
        }
        if (currNode == head)
        {
            head = head->next; // if head node update head
            head->prev = nullptr;
        }
        else if (currNode->prev)
        { // checking if it's old node
            currNode->prev->next = currNode->next;
            currNode->next->prev = currNode->prev;
        }
        tail->next = currNode; // update tail
        currNode->next = nullptr;
        currNode->prev = tail;
        tail = currNode;
    }

    void put(int key, int value)
    {
        if (mp.count(key))
        {
            Node *ptr = mp[key];
            ptr->val = value;
            updateTailNode(ptr);
        }
        else if (mp.size() < capacity)
        {
            Node *newNode = new Node(key, value);
            mp[key] = newNode;
            updateTailNode(newNode);
        }
        else if (capacity != 0)
        {
            Node *ptr = head;
            mp.erase(ptr->key);
            ptr->val = value;
            ptr->key = key;
            mp[key] = ptr;
            updateTailNode(ptr);
        }
    }
};

int main(){
    int capacity;
    cout << "Enter capacity";
    cin >> capacity;
    cout << "KEYWORDS:" << endl;
    cout << "put key val" << endl;
    cout << "get key" << endl;
    cout << "exit" << endl;
    LRUCache *lru=new LRUCache(capacity);
    string s;
    while (s!="exit")
    {
        int key, val;
        cin >> s;
        if (s=="exit")
        {
            break;
        }
        else if(s=="get"){
            cin >> key;
            cout << "value: " << lru->get(key)<<endl;
        }
        else if(s=="put"){
            cin >> key;
            cin >> val;
            lru->put(key, val);
        }
        else{
            cout << "Not valid instruction" << endl;
        }
        
    }
    
}
