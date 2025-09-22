#include <iostream>
using namespace std;

// topic: BST + dfs
// time-complexity: O(n)
// space-complexity: O(n)

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
        {
            return nullptr;
        }

        if (root->val == key)
        {
            if (!root->right)
            {
                TreeNode *left = root->left;
                delete root;
                return left;
            }
            else if (!root->left)
            {
                TreeNode *right = root->right;
                delete root;
                return right;
            }
            else
            {
                TreeNode *left = root->left;
                TreeNode *right = root->right;
                delete root;
                TreeNode *leftMost = right;
                while (leftMost->left)
                {
                    leftMost = leftMost->left;
                }
                leftMost->left = left;
                return right;
            }
        }
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else
            root->right = deleteNode(root->right, key);
        return root;
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
    int val;
    cout << "Enter value: ";
    cin >> val;
    Solution s;
    root = s.deleteNode(root, val);
    cout << "inorder: " << endl;
    display(root);
    cout << endl;
}