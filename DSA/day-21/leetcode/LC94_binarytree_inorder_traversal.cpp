#include<iostream>
#include<vector>
using namespace std;

// topic: binary tree + inorder traversal
// time-complexity: O(n)
// space-complexity: O(h); h=height of tree

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
private:
    void dfs(TreeNode *root, vector<int> &ans)
    {
        if (!root)
        {
            return;
        }
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        ans.reserve(100);
        dfs(root, ans);
        return ans;
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

int main(){
    cout << "Enter elements of tree in preorder: ";
    TreeNode *root = buildTreePreorder();
    Solution s;
    vector<int> ans = s.inorderTraversal(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}