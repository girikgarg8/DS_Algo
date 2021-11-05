// Given a binary matrix of M X N of integers,
// you need to return only unique rows of binary array
#include <bits/stdc++.h>
using namespace std;
#define ROW 4
#define COL 5

// The main function that prints
// all unique rows in a given matrix.
void findUniqueRows_brute_Force(int M[ROW][COL])
{
    //Traverse through the matrix
    for (int i = 0; i < ROW; i++)
    {
        int flag = 0;

        //check if there is similar column
        //is already printed, i.e if i and
        //jth column match.
        for (int j = 0; j < i; j++)
        {
            flag = 1;

            for (int k = 0; k <= COL; k++)
                if (M[i][k] != M[j][k])
                    flag = 0;

            if (flag == 1)
                break;
        }

        //if no row is similar
        if (flag == 0)
        {
            //print the row
            for (int j = 0; j < COL; j++)
                cout << M[i][j] << " ";
            cout << endl;
        }
    }
}
class BST
{
    int data;
    BST *left, *right;

public:
    // Default constructor.
    BST();

    // Parameterized constructor.
    BST(int);

    // Insert function.
    BST *Insert(BST *, int);

    // Inorder traversal.
    void Inorder(BST *);
};

//convert array to decimal
int convert(int arr[])
{
    int sum = 0;

    for (int i = 0; i < COL; i++)
    {
        sum += pow(2, i) * arr[i];
    }
    return sum;
}

//print the column represented as integers
void print(int p)
{
    for (int i = 0; i < COL; i++)
    {
        cout << p % 2 << " ";
        p /= 2;
    }
    cout << endl;
}

// Default Constructor definition.
BST ::BST() : data(0), left(NULL), right(NULL) {}

// Parameterized Constructor definition.
BST ::BST(int value)
{
    data = value;
    left = right = NULL;
}

// Insert function definition.
BST *BST ::Insert(BST *root, int value)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }

    //if the value is present
    if (value == root->data)
        return root;

    // Insert data.
    if (value > root->data)
    {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else
    {
        // Insert left node data, if the 'value'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, value);
    }

    // Return 'root' node, after insertion.
    return root;
}

// Inorder traversal function.
// This gives data in sorted order.
void BST ::Inorder(BST *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    print(root->data);
    Inorder(root->right);
}

// The main function that prints
// all unique rows in a given matrix.
void findUniqueRows(int M[ROW][COL])
{

    BST b, *root = NULL;

    //Traverse through the matrix
    for (int i = 0; i < ROW; i++)
    {
        //insert the row into BST
        root = b.Insert(root, convert(M[i]));
    }

    //print
    b.Inorder(root);
}
#include <iostream>
using namespace std;
#define ROW 4
#define COL 5
class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[2];
        for (int i = 0; i < 2; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode(30);
    }

private:
    void insertWord(TrieNode *root, string word)
    {
        //Base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        //Small calculation
        int index = word[0] - '0';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        //Recursive call
        insertWord(child, word.substr(1));
    }
    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return true;
        }
        int index = word[0] - '0';
        if (root->children[index] == NULL)
        {
            return false;
        }
        return search(root->children[index], word.substr(1));
    }
    void deleteWord(TrieNode *root, string word)
    {
        //Base case
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        //Small calculation part
        TrieNode *child;
        int index = word[0] - '0';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            //word not found
            return;
        }
        deleteWord(child, word.substr(1));
        //remove child-node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 2; i++)
            {
                if (child->children[i] != NULL)
                {
                    return;
                }
            }
        }
        delete child;
        root->children[index] = NULL;
    }

public:
    void insertWord(string word)
    {
        insertWord(root, word);
    }
    bool search(string word)
    {
        return search(root, word);
    }
    void deleteWord(string word)
    {
        deleteWord(word);
    }
};
void displayAllWordshelper(TrieNode *root, string &str)
{
    if (root->isTerminal)
    {
        cout << str << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        if (root->children[i])
        {
            str = str + to_string(i);
            displayAllWordshelper(root->children[i], str);
        }
    }
    str.pop_back();
}
void displayAllWords(Trie t1)
{
    TrieNode *root = t1.root;
    string x = "";
    displayAllWordshelper(root, x);
}
void insertMatrix(int mat[ROW][COL])
{
    Trie t1;
    for (int i = 0; i < ROW; i++)
    {
        string str = "";
        for (int j = 0; j < COL; j++)
        {
            str += to_string(mat[i][j]);
        }
        t1.insertWord(str);
    }
    displayAllWords(t1);
}
int main()
{
    int M[ROW][COL] = {{0, 1, 0, 0, 1},
                       {1, 0, 1, 1, 0},
                       {0, 1, 0, 0, 1},
                       {1, 1, 1, 0, 0}};
    insertMatrix(M);
}

// Driver Code
int main()
{
    int M[ROW][COL] = {{0, 1, 0, 0, 1},
                       {1, 0, 1, 1, 0},
                       {0, 1, 0, 0, 1},
                       {1, 0, 1, 0, 0}};

    findUniqueRows_brute_Force(M);

    return 0;
}
