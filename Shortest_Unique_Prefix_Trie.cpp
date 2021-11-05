#include <iostream>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode ** children;
    bool isTerminal;
    int freq;
    TrieNode(char data){
        this->data=data;
        children=new TrieNode *[26];
        for (int i=0;i<26;i++){
            children[i]=NULL;
        }
        freq=0;
        isTerminal=false;
    }
};
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
            child->freq++;
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
            child->freq++;
        }
        //Recursive call
        insertWord(child,word.substr(1));
    }
    public:
    void insertWord(string word){
        insertWord(root,word);
    }
    void findPrefix(TrieNode *root,string &str){
        if (root->freq==1){
            cout << str << endl;
            str.pop_back();
            return ;
        }
        for (int i=0;i<26;i++){
            if (root->children[i]!=NULL){
                str+=root->children[i]->data;
                findPrefix(root->children[i],str);
            }
        }
        str.pop_back();
    }
    void findprefixHelper(){
        string x="";
        findPrefix(this->root,x);
    }
};
// Not attempted the sorting approach to this question as it was difficult
int main(){
    Trie t1;
    t1.insertWord("helper");
    t1.insertWord("helps");
    t1.insertWord("short");
    t1.insertWord("shopkeeper");
    t1.insertWord("ship");
    t1.findprefixHelper();
    return 0;
}
