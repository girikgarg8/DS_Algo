#include "TrieNodeClass.h"
#include <bits/stdc++.h>
class Trie{
    public:
    TrieNode *root;
    Trie(){
        root=new TrieNode('\0');
    }
    private:
    void insertWord(TrieNode *root,string word){
        //Base case
        if(word.size()==0){
            root->isTerminal=true;
            return ;
        }
        //Small calculation
        int index=word[0]-'a';
        TrieNode *child;
        if (root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        //Recursive call
        insertWord(child,word.substr(1));
    }
    bool search(TrieNode *root,string word){
        if (word.size()==0){
            return true;
        }
        int index=word[0]-'a';
        if (root->children[index]==NULL){
            return false;
        }
        return search(root->children[index],word.substr(1));
    }
    void deleteWord(TrieNode *root,string word){
        //Base case
        if (word.size()==0){
            root->isTerminal=false;
            return ;
        }
        //Small calculation part
        TrieNode *child;
        int index=word[0]-'a';
        if (root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            //word not found
            return ;
        }
        deleteWord(child,word.substr(1));
        //remove child-node if it is useless
        if (child->isTerminal==false){
            for (int i=0;i<26;i++){
                if (child->children[i]!=NULL){
                    return ;
                }
            }
        }
        delete child;
        root->children[index]=NULL;
    }
    public:
    void insertWord(string word){
        insertWord(root,word);
    }
    bool search(string word){
        return search(root,word);
    }
    void deleteWord(string word){
        deleteWord(word);
    }

};