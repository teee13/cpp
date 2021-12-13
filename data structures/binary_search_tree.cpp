#include <iostream>
using namespace std;
struct BstNode
{
    int data;
    BstNode *right_child;
    BstNode *left_child;
};
BstNode *getNode(int data)
{
    BstNode *newnode = new BstNode();
    newnode->data = data;
    newnode->left_child = NULL;
    newnode->right_child = NULL;

    return newnode;
}
BstNode *insert(BstNode *root, int data)
{
    if (root == NULL)
    {
        getNode(data);
        return root;
    }
    else if (root->data >= data)
    {
        root->left_child = insert(root->left_child, data);
        return root;
    }
    else
    {
        root->right_child = insert(root->right_child, data);
        return root;
    }
}
int main()
{
    BstNode *root = NULL;

    root = insert(root, 10);
    root = insert(root, 35);
    root = insert(root, 18);
    return 0;
}
