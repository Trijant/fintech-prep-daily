#include <iostream>
#include <queue>
using namespace std;

// topic: BT+ BFS + right side view
// time-complexity: O(n)
// space-complexity: O(L+W); L=level of BT, W=width of tree

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
    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);

        vector<int> ans;
        ans.reserve(100);

        while (!q.empty())
        {
            int size = q.size();
            TreeNode *cur;
            for (int i = 0; i < size; i++)
            {
                cur = q.front();
                q.pop();
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            ans.push_back(cur->val);
        }
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

int main()
{
    cout << "Enter elements of tree in preorder: ";
    TreeNode *root = buildTreePreorder();
    Solution s;
    vector<int> ans = s.rightSideView(root);
    cout << "Right side view: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}