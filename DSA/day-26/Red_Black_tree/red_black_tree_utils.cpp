#include <iostream>
using namespace std;

// topic: red black tree

struct TreeNode
{
    int val;
    bool isBlack;
    int count;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        isBlack = false;
        count = 1;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class RedBlackTree
{
private:
    TreeNode *root;
    int size;

    void leftRotate(TreeNode *root)
    {
        TreeNode *rightNode = root->right;
        TreeNode *parent = root->parent;
        root->right = rightNode->left;
        rightNode->left->parent = root;
        rightNode->left = root;
        rightNode->parent = parent;
        root->parent = rightNode;
        if (!parent)
            root = rightNode;
        else if (parent->left == root)
            parent->left = rightNode;
        else
            parent->right = rightNode;
    }
    void rightRotate(TreeNode *root)
    {
        TreeNode *leftNode = root->left;
        TreeNode *parent = root->parent;
        root->left = leftNode->right;
        leftNode->right->parent = root;
        leftNode->right = root;
        leftNode->parent = root->parent;
        root->parent = leftNode;
        if (!parent)
            root = leftNode;
        else if (parent->left == root)
            parent->left = leftNode;
        else
            parent->right = leftNode;
    }

    void insertHelper(int val)
    {
        TreeNode *curNode = new TreeNode(val);
        if (!root)
        {
            curNode->isBlack = true;
            root = curNode;
            return;
        }
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->val > val)
            {
                if (!cur->left)
                {
                    cur->left = curNode;
                    curNode->parent = cur;
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
            else if (cur->val < val)
            {
                if (!cur->right)
                {
                    cur->right = curNode;
                    curNode->parent = cur;
                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
            else
            {
                cur->count++;
                return;
            }
        }
        if (curNode->parent->isBlack || !curNode->parent->parent)
            return;
        else
        {
            TreeNode *gp = curNode->parent->parent;
            if (curNode->parent == gp->left)
            {
                TreeNode *uncle = gp->right;
                if (uncle->isBlack)
                {
                    if (curNode == curNode->parent->right)
                    {
                        curNode = curNode->parent;
                        leftRotate(curNode);
                    }
                    curNode->isBlack = true;
                    rightRotate(gp);
                }
                else{
                    curNode->parent->isBlack = true;
                    uncle->isBlack = true;
                    gp->isBlack = false;
                }
            }
            else
            {
                TreeNode *uncle = gp->left;
            }
        }
    }

public:
    RedBlackTree()
    {
        root = nullptr;
        size = 0;
    }

    void insertNode(int val)
    {
        insertHelper(val);
        size++;
    }
};