#include <iostream>
#include <queue>
using namespace std;

// topic: AVL tree(self balancing tree)

struct TreeNode
{
    int val;
    int height;
    int count;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        height = 1;
        left = right = nullptr;
        count = 1;
    }
};

class AVLTree
{
private:
    TreeNode *root;
    int size;

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
        else if (root->val < val)
            root->right = insertHelper(root->right, val);
        else
            root->count++;
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
        else if(root->count>1)
            root->count--;
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

    string centerValue(string s, int width)
    {
        int total = width - s.size();
        int left = total / 2;
        int right = total - left;
        return string(left, ' ') + s + string(right, ' ');
    }

    void displayHelper(TreeNode *root)
    {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        int height = root->height;
        TreeNode *tmp = root;

        int width = 11 << (height - 1);

        while (!q.empty())
        {
            height--;
            int sz = q.size();

            for (int i = 0; i < sz; ++i)
            {
                TreeNode *node = q.front();
                q.pop();
                
                if (node)
                    cout << centerValue(to_string(node->val), width);
                else
                cout << centerValue("null", width);

                if (node)
                {
                    q.push(node->left);
                    q.push(node->right);
                }
                else
                {
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
            cout << "\n\n";
            if (!height)
                break;
            width = width >> 1;
        }
    }
    TreeNode* findNode(TreeNode* root,int val){
        if(!root)
            return nullptr;
        if(root->val==val)
            return root;
        else if(root->val>val)
            return findNode(root->left, val);
        else
            return findNode(root->right, val);
    }

    void emptyTreeHelper(TreeNode *root)
    {
        if (!root)
            return;
        emptyTreeHelper(root->left);
        emptyTreeHelper(root->right);
        delete root;
    }

    public:
    AVLTree()
    {
        root = nullptr;
        size = 0;
    }
    ~AVLTree()
    {
        emptyTreeHelper(root);
        root = nullptr;
        size = 0;
    }
    void insertNode(int val)
    {
        root = insertHelper(root, val);
        size++;
    }
    void deleteNode(int val)
    {
        root = deleteHelper(root, val);
        size--;
    }
    void updateNode(int curVal, int newVal)
    {
        deleteNode(curVal);
        insertNode(newVal);
    }
    void display()
    {
        displayHelper(root);
    }
    int count(int val){
        TreeNode* cur=findNode(root, val);
        return (cur ? cur->count : -1);
    }
    int getSize(){
        return size;
    }
    void emptyTree(){
        emptyTreeHelper(root);
        root = nullptr;
        size = 0;
    }
};

int main()
{
    cout << "Instructions:" << endl;
    cout << "insert <val>" << endl;
    cout << "delete <val>" << endl;
    cout << "update <curval> <newval>" << endl;
    cout << "display" << endl;
    cout << "count <val>" << endl;
    cout << "size" << endl;
    cout << "empty" << endl;
    cout << "exit" << endl;

    AVLTree *avl = new AVLTree();

    while (true)
    {
        string i;
        cin >> i;
        if (i == "exit")
        {
            break;
        }
        else if (i == "insert")
        {
            int val;
            cin >> val;
            avl->insertNode(val);
        }
        else if (i == "delete")
        {
            int val;
            cin >> val;
            avl->deleteNode(val);
        }
        else if (i == "update")
        {
            int curVal, newVal;
            cin >> curVal >> newVal;
            avl->updateNode(curVal, newVal);
        }
        else if (i == "display")
        {
            avl->display();
        }
        else if(i=="count"){
            int val;
            cin >> val;
            cout << "count: " << avl->count(val)<<endl;
        }
        else if(i=="size"){
            cout << "size: " << avl->getSize()<<endl;
        }
        else if(i=="empty"){
            avl->emptyTree();
        }
        else
        {
            cout << "Invalid instruction!" << endl;
        }
    }
}