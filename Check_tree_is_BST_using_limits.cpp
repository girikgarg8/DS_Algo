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
class BSTOutput{
    public:
    int min;
    int max;
    bool isBST;
};
BSTOutput checkISBST(TreeNode *root){
  if (root==NULL){
      BSTOutput output;
      output.min=INT_MAX;
      output.max=INT_MIN;
      output.isBST=true;
      return output;
  }
  BSTOutput isBSTLeft=checkISBST(root->left);
  BSTOutput isBSTRight=checkISBST(root->right);
  bool answer=isBSTLeft.isBST && isBSTRight.isBST && isBSTLeft.max <root->data && isBSTRight.min>root->data;
  int minimum=min(root->data,min(isBSTLeft.min,isBSTRight.min));
  int maximum=max(root->data,max(isBSTRight.max,isBSTLeft.max));
  BSTOutput output;
  output.min=minimum;
  output.max=maximum;
  output.isBST=answer;
  return output;
}
bool isBST3(BInaryTreeNode *root,int min=INT_MIN,int max=INT_MAX){
    if (root==NULL){
        return true;
    }
    if (root->data < min || root->data >max){
        return false;
    }
    bool isLeftBST=isBST3(root->left,min,root->data-1);
    bool isRightBST=isBST3(root->right,root->data,max);
    return isLeftBST&&isRightBST;
}
int main()
{
    TreeNode *root = takeInput();
    BSTOutput answer=checkISBST(root);
    cout << answer.isBST <<endl;
    return 0;
}