#include <iostream>
#include <stack>
using namespace std;

// topic: BST + dfs
// time-complexity: O(n)
// space-complexity: O(h)

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int getMinimumDifference(TreeNode *root)
    {
        TreeNode *prev = nullptr;
        TreeNode *cur = root;
        stack<TreeNode *> st;
        int minDiff = INT_MAX;

        while (cur || !st.empty())
        {
            // access left most node
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            // access current node
            cur = st.top();
            st.pop();
            if (prev)
                minDiff = min(minDiff, cur->val - prev->val); // updating min distance
            prev = cur;                                       // updating prev

            cur = cur->right; // accessing right subtree
        }
        return minDiff;
    }
};

// BST insert function
TreeNode *insertBST(TreeNode *root, int val)
{
    if (!root)
        return new TreeNode(val);
    if (val < root->val)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);
    return root;
}

int main()
{
    TreeNode *root = nullptr;
    Solution sol;
    string command;

    cout << "Enter commands: insert <val> or exit\n";

    while (cin >> command)
    {
        if (command == "exit")
            break;

        if (command == "insert")
        {
            int val;
            cin >> val;
            root = insertBST(root, val);
        }
        else
        {
            cout << "Unknown command\n";
        }
    }

    if (root)
    {
        int minDiff = sol.getMinimumDifference(root);
        cout << "Minimum difference in BST: " << minDiff << endl;
    }
    else
    {
        cout << "BST is empty, no minimum difference\n";
    }

    return 0;
}
