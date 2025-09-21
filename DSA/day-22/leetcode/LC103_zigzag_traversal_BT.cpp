#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

// topic: BT + queue + bfs
// time-complexity: O(n)
// space-complexity: O(n)



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
  right(right) {}
  };
 
class Solution
{
private:
    void processLevel(queue<TreeNode *> &q, vector<vector<int>> &ans)
    {
        int size = q.size();
        ans.push_back({});
        ans.back().reserve(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *curNode = q.front();
            q.pop();
            if (curNode->left)
                q.push(curNode->left);
            if (curNode->right)
                q.push(curNode->right);
            ans.back().push_back(curNode->val);
        }
    }

public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ans;
        ans.reserve(2000);

        bool rightToLeft = false;
        while (!q.empty())
        {
            processLevel(q, ans);
            if (rightToLeft)
            {
                reverse(ans.back().begin(), ans.back().end());
            }
            rightToLeft ^= 1;
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
    vector<vector<int>> ans = s.zigzagLevelOrder(root);
    cout << "Zigzag order traversal: "<<endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}