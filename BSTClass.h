#include <iostream>
#include <queue>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
class BST{
    BinaryTreeNode *root;
    public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }
    private:
    BinaryTreeNode* deleteData(int data,BinaryTreeNode *node){
        if (node==NULL){
            return NULL; 
        }
        if (data>node->data){
            node->right=deleteData(data,node->right);
            return node;
        }
        else if (data<node->data){
            node->left=deleteData(data,node->left);
            return node;
        }
        else{
            if (node->left==NULL && node->right==NULL){
                delete node;
                return NULL;
            }
        else if (node->left==NULL){
            BinaryTreeNode *temp=node->right;
            node->right=NULL;
            delete node;
            return temp;
        }
           else if (node->left==NULL){
            BinaryTreeNode *temp=node->right;
            node->right=NULL;
            delete node;
            return temp;
        }
        else{
            BinaryTreeNode *minNode=node->right;
            while (minNode->left!=NULL){
                minNode=minNode->left; //keep on moving left until possible
            }
            int rightMin=minNode->data;
            node->data=rightMin;
            node->right=deleteData(rightMin,node->right);
            return node;
        }
    }
    }
    public:
    void deleteData(int data){
        this->root=deleteData(data,root);
    }
    private:
    BinaryTreeNode * insert (int data,BinaryTreeNode * node){
        if (node==NULL){
            BinaryTreeNode *newNode=new BinaryTreeNode(data);
            return newNode;
        }
        if (data<node->data){
            node->left=insert(data,node->left);
        }
        else{
            node->right=insert(data,node->right);
        }
         return node;
    }
    public:
    void insert(int data){
        this->root=insert(data,root);
    }
    private:
    bool search(int data,BinaryTreeNode *node){
        if (node==NULL){
            return false;
        }
        if (node->data==data){
            return true;
        }
        else if (data<node->data){
            return search(data,node->left);
        }
        else{
            return search(data,node->right);
        }
    }
    public:
    bool search(int data){
        return search(data,root);
    }
    void printLevelWise()
{
    queue<BinaryTreeNode *> q1;
    q1.push(root);
    while (!q1.empty())
    {
        BinaryTreeNode *a = q1.front();
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
};
