#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;

// topic : DLL + mapping + set
// time-complexity: O(1)
// space-complexity: O(n)

struct Node
{
    int count;
    unordered_set<string> keys;
    Node *next;
    Node *prev;
    Node(int count)
    {
        this->count = count;
        next = nullptr;
        prev = nullptr;
    }
};

class AllOne
{
private:
    unordered_map<string, Node *> mp;
    Node *head;
    Node *tail;

public:
    AllOne()
    {
        head = new Node(INT_MIN);
        tail = new Node(INT_MAX);
        head->next = tail;
        tail->prev = head;
    }
    void insertAfterNode(Node *cur, Node *prev)
    {
        prev->next->prev = cur;
        cur->next = prev->next;
        prev->next = cur;
        cur->prev = prev;
    }
    void removeNode(Node *cur)
    {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    void inc(string key)
    {
        if (mp.count(key))
        {
            Node *ptr = mp[key];
            Node *nextNode = ptr->next;
            ptr->keys.erase(key);
            if (ptr->count + 1 == nextNode->count)
            {
                nextNode->keys.insert(key);
                mp[key] = nextNode;
            }
            else
            {
                Node *newNode = new Node(ptr->count + 1);
                newNode->keys.insert(key);
                insertAfterNode(newNode, ptr);
                mp[key] = newNode;
            }
            if (ptr->keys.size() == 0)
            {
                removeNode(ptr);
                delete ptr;
            }
        }
        else
        {
            if (head->next->count == 1)
            {
                head->next->keys.insert(key);
                mp[key] = head->next;
            }
            else
            {
                Node *newNode = new Node(1);
                newNode->keys.insert(key);
                insertAfterNode(newNode, head);
                mp[key] = newNode;
            }
        }
    }

    void dec(string key)
    {
        if (mp.count(key))
        {
            Node *ptr = mp[key];
            Node *prevNode = ptr->prev;
            ptr->keys.erase(key);
            if (ptr->count - 1 == 0)
            {
                mp.erase(key);
            }
            else if (prevNode->count == ptr->count - 1)
            {
                prevNode->keys.insert(key);
                mp[key] = prevNode;
            }
            else
            {
                Node *newNode = new Node(ptr->count - 1);
                newNode->keys.insert(key);
                insertAfterNode(newNode, prevNode);
                mp[key] = newNode;
            }
            if (ptr->keys.size() == 0)
            {
                removeNode(ptr);
                delete ptr;
            }
        }
    }

    string getMaxKey()
    {
        return (tail->prev == head) ? "" : *(tail->prev->keys.begin());
    }

    string getMinKey()
    {
        return (head->next == tail) ? "" : *(head->next->keys.begin());
    }
};

int main(){
    AllOne *a = new AllOne();
    cout<<"Instructions:"<<endl;
    cout << "INC key" << endl;
    cout << "DCR key" << endl;
    cout << "min" << endl;
    cout << "max" << endl;
    while (true)
    {
        string i;
        cin >> i;
        if(i=="exit"){
            break;
        }
        else if(i=="INC"){
            string key;
            cin>>key;
            a->inc(key);
        }
        else if(i=="DCR"){
            string key;
            cin >> key;
            a->dec(key);
        }
        else if(i=="min"){
            cout << "Min: " << a->getMinKey()<<endl;
        }
        else if(i=="max"){
            cout << "Max: " << a->getMaxKey()<<endl;
        }
        else{
            cout << "Invalid instruction" << endl;
        }
    }
    
}