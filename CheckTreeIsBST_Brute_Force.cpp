#include <iostream>
#include <climits>
#include <queue>
#include "BinaryTreeNode.h"
TreeNode *takeInput()
{
    int rootData;
    int leftchildData;
    int rightchildData;
    cout << "Enter the root data:" << endl;
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *leftChild;
        TreeNode *rightChild;
        TreeNode *a = q1.front();
        q1.pop();
        cout << "Enter the left child data"
             << " of " << a->data << endl;
        cin >> leftchildData;
        if (leftchildData == (-1))
        {
            leftChild = NULL;
        }
        else
        {
            leftChild = new TreeNode(leftchildData);
            q1.push(leftChild);
        }
        cout << "Enter the right child data"
             << " of" << a->data << endl;
        cin >> rightchildData;
        if (rightchildData == (-1))
        {
            rightChild = NULL;
        }
        else
        {
            rightChild = new TreeNode(rightchildData);
            q1.push(rightChild);
        }
        if (a != NULL)
        {
            a->left = leftChild;
            a->right = rightChild;
        }
    }
    return root;
}
void printLevelWise(TreeNode *root)
{
    queue<TreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        TreeNode *a = q1.front();
        q1.pop();
        cout << endl;
        cout << a->data << ":";
        if (a->left != NULL)
        {
            cout << " L" << a->left->data;
            q1.push(a->left);
        }
        if (a->right != NULL)
        {
            cout << " R" << a->right->data;
            q1.push(a->right);
        }
    }
}
int findMinimumElement(TreeNode *root){
    if (root==NULL){
        return INT_MAX;
    }
    int minInLeftSubtree=findMinimumElement(root->left);
    int minInRightSubtree=findMinimumElement(root->right);
    return min(root->data,minInLeftSubtree,minInRightSubtree);
}
int findMaximumElement(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    int minInLeftSubtree = findMaximumElement(root->left);
    int minInRightSubtree = findMaximumElement(root->right);
    return max(root->data, minInLeftSubtree, minInRightSubtree);
}
bool checkISBST(TreeNode *root){
    if (root==NULL){
        return true;
    }
    int maxElementInLeft=findMaximumElement(root->left);
    int minElementInRight = findMinimumElement(root->right);
    bool a=checkISBST(root->left) && checkISBST(root->right) && maxElementInLeft<=root->data && minElementInRight>=root->data ;
    return a;
}
int main()
{
    TreeNode *root = takeInput();
    printLevelWise(root);
    cout << "Answer is " << checkISBST(root);
    return 0;
}