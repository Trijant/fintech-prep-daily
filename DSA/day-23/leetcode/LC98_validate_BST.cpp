#include <iostream>
#include <stack>
using namespace std;

// topic: BST + dfs
// time-complexity: O(n)
// space-complexity: O(h); h=height of tree

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
    bool isValidBST(TreeNode *root)
    {
        long prev = LONG_MIN;
        stack<TreeNode *> st;
        TreeNode *curr = root;

        while (curr || !st.empty())
        {
            // Go to leftmost
            while (curr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            // Check BST property
            if (curr->val <= prev)
                return false;
            prev = curr->val;

            // Go right
            curr = curr->right;
        }
        return true;
    }
};

TreeNode *buildTreePreorder()
{
    int val;
    cin >> val;
    if (val == -1)
        return nullptr;

    TreeNode *root = new TreeNode(val);
    root->left = buildTreePreorder();
    root->right = buildTreePreorder();
    return root;
}

void display(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    display(root->left);
    cout << root->val << " ";
    display(root->right);
}

int main()
{
    cout << "Enter elements of tree in preorder: ";
    TreeNode *root = buildTreePreorder();
    Solution s;
    if (s.isValidBST(root))
    {
        cout << "It is valid BST!" << endl;
    }
    else
    {
        cout << "It is not valid BST!" << endl;
    }
}