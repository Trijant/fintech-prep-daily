#include<iostream>
using namespace std;

// topic: BST + dfs
// time-complexity: O(n)
// space-complexity: O(1)

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
    TreeNode *lowestCommonAncestor(TreeNode *root, int p,  int q)
    {
        int minVal, maxVal;
        if (p < q)
        {
            minVal = p;
            maxVal = q;
        }
        else
        {
            minVal = q;
            maxVal = p;
        }
        TreeNode *cur = root;
        while (cur)
        {
            int val = cur->val;

            // Both nodes in left subtree
            if (val > maxVal)
            {
                cur = cur->left;
            }
            // Both nodes in right subtree
            else if (val < minVal)
            {
                cur = cur->right;
            }
            // Split point found
            else
            {
                break;
            }
        }
        return cur;
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
    cout << "Enter p and q: ";
    int p, q;
    cin >> p >> q;
    Solution s;
    TreeNode *lowestCommonAncestor = s.lowestCommonAncestor(root, p, q);
    cout << "LowestCommonAncestor: " << lowestCommonAncestor->val << endl;
}