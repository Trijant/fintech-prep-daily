#include<iostream>
using namespace std;

// topic: BST + dfs
// time-complexity: O(n)
// space-complexity: O(n)



  struct TreeNode {
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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
        {
            return new TreeNode(val);
        }
        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        else
        {
            root->right = insertIntoBST(root->right, val);
        }
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

void display(TreeNode * root){
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
    root = s.insertIntoBST(root,val);
    cout <<"inorder: "<< endl;
    display(root);
    cout << endl;
}