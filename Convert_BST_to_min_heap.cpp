#include <iostream>
#include <vector>
#include "BinaryTreeNode.h"
using namespace std;
void inorder_traversal (TreeNode *root,vector <int> &arrayWithNodes){
    if (root==NULL){
        return ;
    }
    inorder_traversal(root->left,arrayWithNodes);
    arrayWithNodes.push_back(root->data);
    inorder_traversal(root->right,arrayWithNodes);
}
void convertToHeap (TreeNode *root,vector <int> &arr,int idx){
    if (root==NULL){
        return ;
    }
    root->data=arr[idx];
    idx++;
    convertToHeap(root->left,arr,idx);
    convertToHeap(root->right,arr,idx);
}
TreeNode * convertBST (TreeNode *root){
    vector <int> arrayWithNodes;
    inorder_traversal(root,arrayWithNodes);
    int idx=0;
    convertToHeap(root,arrayWithNodes,idx);
    return root;
}
