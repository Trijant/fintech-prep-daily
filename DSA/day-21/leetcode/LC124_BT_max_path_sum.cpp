#include <iostream>
#include<climits>
using namespace std;

// topic: Binary tree + DFS
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
private:
    int dfs(TreeNode *root, int &maxSum)
    {
        if (!root)
        {
            return 0;
        }
        int leftSum = dfs(root->left, maxSum);
        int rightSum = dfs(root->right, maxSum);
        maxSum = max(maxSum, leftSum + rightSum + root->val);
        int curSum = max(leftSum, rightSum) + root->val;
        return (curSum > 0 ? curSum : 0);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
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
    cout << "Enter elements of tree in preorder: ";
    TreeNode *root = buildTreePreorder();
    Solution s;
    int ans = s.maxPathSum(root);
    cout << "Max path sum: " << ans << endl;
}