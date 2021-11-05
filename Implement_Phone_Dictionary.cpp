#include <iostream>
#include "Trie.h"
using namespace std; 
TrieNode *root;// Making root NULL for ease so that it doesn't
// have to be passed to all functions.

// Display suggestions after every character entered by 
// the user for a given query string 'str'
// This function simply displays all dictionary words
// going through current node. String 'prefix'
// represents string corresponding to the path from
// root to curNode.
void displayContactsUtil(TrieNode *curNode, string prefix)
{
    // Check if the string 'prefix' ends at this Node
    // If yes then display the string found so far
    if (curNode->isTerminal==true)
        cout << prefix << endl;
  
    // Find all the adjacent Nodes to the current
    // Node and then call the function recursively
    // This is similar to performing DFS on a graph
    for (char i = 'a'; i <= 'z'; i++)
    {
        int index=i-'a';
        TrieNode *nextNode = curNode->children[index];
        if (nextNode != NULL)
            displayContactsUtil(nextNode, prefix + (char)i);
    }
}
void displayContacts(string str){
    TrieNode *prevNode=root;
    string prefix="";
    int len=str.length();
    // Display the contact List for string formed
    // after entering every character
    int i;
    for (i=0; i<len; i++)
    {
        // 'prefix' stores the string formed so far
        prefix += (char)str[i];
  
        // Get the last character entered
        char lastChar = prefix[i];
        
        int index=lastChar-'a';
        // Find the Node corresponding to the last
        // character of 'prefix' which is pointed by
        // prevNode of the Trie
        TrieNode *curNode=prevNode->children[index];
        // If nothing found, then break the loop as
        // no more prefixes are going to be present.
        if (curNode == NULL)
        {
            cout << "\n" << "No Results Found for "<< prefix
                 << "\n";
            i++;
            break;
        }
        // If present in trie then display all
        // the contacts with given prefix.
        cout << "\n" << "Suggestions based on " << prefix
             << " are " << "\n";
        displayContactsUtil(curNode, prefix);
  
        // Change prevNode for next prefix
        prevNode = curNode;
    }
      for (; i<len; i++)
    {
        prefix += (char)str[i];
        cout << "No Results Found for"  << prefix
             << "\n";
    }
}
int main(){
    Trie t1;
    t1.insertWord("geeksquiz");
    t1.insertWord("gforgeeks");
    root=t1.root;
    displayContacts("gekk");
    return 0;
}
