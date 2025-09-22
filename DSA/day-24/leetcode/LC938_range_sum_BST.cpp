#include <iostream>
#include <stack>
using namespace std;

/*
Topic: BST + Iterative DFS
Time Complexity: O(n) worst case
Space Complexity: O(h)
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Insert function for BST
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

class Solution
{
public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (!root)
            return 0;
        int sum = 0;
        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode *cur = st.top();
            st.pop();

            if (cur->val >= low && cur->val <= high)
                sum += cur->val;

            if (cur->val <= high && cur->right)
                st.push(cur->right);
            if (cur->val >= low && cur->left)
                st.push(cur->left);
        }
        return sum;
    }
};

int main()
{
    TreeNode *root = nullptr;
    Solution s;

    cout << "Enter commands (insert <val> or exit):\n";
    string command;
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

    int low, high;
    cout << "Enter low and high for range sum: ";
    cin >> low >> high;

    int sum = s.rangeSumBST(root, low, high);
    cout << "Range Sum: " << sum << endl;

    return 0;
}
