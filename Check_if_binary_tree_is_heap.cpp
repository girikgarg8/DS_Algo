#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
bool isHeap(TreeNode *root){
     queue<TreeNode*> q;
    q.push(root);
    bool nullish = false;
    while (!q.empty())
    {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->left)
        {
            if (nullish
                || temp->left->data
                >= temp->data)
            {
                return false;
            }
            q.push(temp->left);
        }
        else {
            nullish = true;
        }
        if (temp->right)
        {
            if (nullish
                || temp->right->data
                >= temp->data)
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            nullish = true;
        }
    }
    return true;
}