#include <iostream>
#include <stack>
using namespace std;

// topic: AVL tree(self balancing tree)

struct TreeNode
{
    int val;
    int height;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        height = 1;
        left = right = nullptr;
    }
};

class AVLTree
{
private:
    TreeNode *root;

    TreeNode *rightRotation(TreeNode *root)
    {
        TreeNode *leftNode = root->left;
        root->left = leftNode->right;
        leftNode->right = root;
        setHeight(root);
        setHeight(leftNode);
        return leftNode;
    }
    TreeNode *leftRotation(TreeNode *root)
    {
        TreeNode *rightNode = root->right;
        root->right = rightNode->left;
        rightNode->left = root;
        setHeight(root);
        setHeight(rightNode);
        return rightNode;
    }
    TreeNode *leftRightRotation(TreeNode *root)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }
    TreeNode *rightLeftRotation(TreeNode *root)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }
    void setHeight(TreeNode *root)
    {
        int leftHeight = (root->left ? root->left->height : 0);
        int rightHeight = (root->right ? root->right->height : 0);
        root->height = max(leftHeight, rightHeight) + 1;
    }
    int getBF(TreeNode *root)
    {
        int leftHeight = (root->left ? root->left->height : 0);
        int rightHeight = (root->right ? root->right->height : 0);
        return leftHeight - rightHeight;
    }
    TreeNode *balanceTree(TreeNode *root)
    {

        int BF = getBF(root);
        if (BF > 1)
        {
            int leftBF = getBF(root->left);
            if (leftBF > 0)
                root = rightRotation(root);
            else
                root = leftRightRotation(root);
        }
        else if (BF < -1)
        {
            int rightBF = getBF(root->right);
            if (rightBF < 0)
                root = leftRotation(root);
            else
                root = rightLeftRotation(root);
        }
        setHeight(root);
        return root;
    }

    TreeNode *insertHelper(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);
        if (root->val > val)
            root->left = insertHelper(root->left, val);
        else
            root->right = insertHelper(root->right, val);
        root = balanceTree(root);
        return root;
    }

    TreeNode *deleteHelper(TreeNode *root, int val)
    {
        if (!root)
            return nullptr;

        if (root->val > val)
            root->left = deleteHelper(root->left, val);
        else if (root->val < val)
            root->right = deleteHelper(root->right, val);
        else
        {
            if (!root->left)
            {
                TreeNode *rightNode = root->right;
                delete root;
                return rightNode;
            }
            else if (!root->right)
            {
                TreeNode *leftNode = root->left;
                delete root;
                return leftNode;
            }
            else
            {
                TreeNode *temp = root->right;
                while (temp->left)
                    temp = temp->left;
                root->val = temp->val;
                root->right = deleteHelper(root->right, temp->val);
            }
        }
        root = balanceTree(root);
        return root;
    }

    void emptyTree(TreeNode *root)
    {
        if (!root)
            return;
        emptyTree(root->left);
        emptyTree(root->right);
        delete root;
    }

public:
    AVLTree()
    {
        root = nullptr;
    }
    ~AVLTree()
    {
        emptyTree(root);
        root = nullptr;
    }
    void insertNode(int val)
    {
        root = insertHelper(root, val);
    }
    void deleteNode(int val)
    {
        root = deleteHelper(root, val);
    }
    void updateNode(int curVal, int newVal)
    {
        root = deleteHelper(root, curVal);
        root = insertHelper(root, newVal);
    }
};