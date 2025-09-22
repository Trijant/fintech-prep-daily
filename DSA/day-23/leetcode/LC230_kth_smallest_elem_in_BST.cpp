#include <iostream>
#include <stack>
using namespace std;

// topic: BST + iterative in-order traversal
// time-complexity: O(h + k), worst-case O(n)
// space-complexity: O(h), worst-case O(n)

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
    int kthSmallest(TreeNode *root, int k)
    {
        if (k <= 0)
            return -1;

        int count = 0; // track number of nodes visited
        TreeNode *cur = root;
        stack<TreeNode *> st;

        while (cur || !st.empty())
        {
            // go to leftmost child
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            // visit node
            cur = st.top();
            st.pop();
            count++;
            if (count == k)
                return cur->val;

            // move to right subtree
            cur = cur->right;
        }

        return -1; // k is larger than number of nodes
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

int main()
{
    cout << "Enter elements of tree in preorder (-1 for null nodes): ";
    TreeNode *root = buildTreePreorder();
    cout << "Enter k: ";
    int k;
    cin >> k;

    Solution s;
    int kth = s.kthSmallest(root, k);
    if (kth != -1)
        cout << "kth Smallest Element: " << kth << endl;
    else
        cout << "Invalid k" << endl;
}
