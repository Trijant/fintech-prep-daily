#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// topic: BT + dfs + queue
// time-complexity: O(n)
// space-complexity: O(n)

struct Node
{
    int data;
    Node* left, * right;
    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
}; 

class Solution
{
private:
    void helper(Node *root, vector<int> &ans, queue<Node *> &leftQueue)
    {
        if (!root)
        {
            return;
        }
        ans.push_back(root->data);

        leftQueue.push(root->left);
        helper(root->right, ans, leftQueue);

        Node *left = leftQueue.front();
        leftQueue.pop();
        helper(left, ans, leftQueue);
    }

public:
    vector<int> diagonal(Node *root)
    {
        // code here
        vector<int> ans;
        ans.reserve(10000);
        queue<Node *> leftQueue;
        helper(root, ans, leftQueue);

        return ans;
    }
};

Node *buildTreePreorder()
{
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;

    Node *root = new Node(val);
    root->left = buildTreePreorder();
    root->right = buildTreePreorder();
    return root;
}

int main()
{
    cout << "Enter elements of tree in preorder: ";
    Node *root = buildTreePreorder();
    Solution s;
    vector<int> ans = s.diagonal(root);
    cout << "Diagonal order traversal: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}