#include <bits/stdc++.h>
using namespace std;

// topic: BT + greed traversal + bfs + map +multiset(ordered set with duplicate insertion allowed)
// time-complexity: O(n*log n)
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
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        // col -> row -> multiset of values
        map<int, map<int, multiset<int>>> nodes;

        // BFS queue: node, row, col
        queue<tuple<TreeNode *, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty())
        {
            auto [node, row, col] = q.front();
            q.pop();

            nodes[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, row + 1, col - 1});
            if (node->right)
                q.push({node->right, row + 1, col + 1});
        }

        vector<vector<int>> ans;
        for (auto &[col, mp] : nodes)
        {
            vector<int> colVals;
            for (auto &[row, vals] : mp)
            {
                colVals.insert(colVals.end(), vals.begin(), vals.end());
            }
            ans.push_back(move(colVals));
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
    vector<vector<int>> ans = s.verticalTraversal(root);
    cout << "Vertical order traversal: ";
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}