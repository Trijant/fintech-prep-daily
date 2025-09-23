#include <iostream>
using namespace std;

// topic: Binary Tree + symmetry check
// time-complexity: O(n)
// space-complexity: O(h) (recursion stack)

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
private:
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right || left->val != right->val)
            return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return helper(root->left, root->right);
    }
};

// Preorder DFS tree builder using space-separated input with -1 as null
TreeNode *buildTreePreorder()
{
    int val;
    if (!(cin >> val))
        return nullptr; // no more input
    if (val == -1)
        return nullptr;

    TreeNode *node = new TreeNode(val);
    node->left = buildTreePreorder();
    node->right = buildTreePreorder();
    return node;
}

int main()
{
    cout << "Enter preorder of tree with -1 for null nodes:\n";
    TreeNode *root = buildTreePreorder();

    Solution s;
    if (s.isSymmetric(root))
        cout << "The tree is symmetric.\n";
    else
        cout << "The tree is not symmetric.\n";

    return 0;
}
