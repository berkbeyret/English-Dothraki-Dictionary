#include "Trie.h"

struct TrieNode{
    TrieNode *children[alphabetSize];
    bool isEndOfWord;
    string meaning;
    int countChildren;
};


TrieNode* Trie::newTrieNode(){
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    node->countChildren = 0;
    for(int i = 0; i < alphabetSize; i++){
        node->children[i] = NULL;
    }
    return node;
}

void Trie::insert(string word, string meaning){

    TrieNode* temp = root;
    for (int i = 0; i < word.length(); i++) {
        char x = word[i];

        // Make a new node if there is no path
        if (temp->children.find(x) == temp->map.end()){
            temp->map[x] = newTrieNode();
        }


        temp = temp->children[x];
    }

    // Mark end of word and store the meaning
    temp->isEndOfWord = true;
    temp->meaning = meaning;
}

string Trie::getMeaning(Trie* root, const string& word){

    // If root is null i.e. the dictionary is empty
    if (root == NULL){
        return "";
    }

    Trie* temp = root;

    // Search a word in the Trie
    for (int i = 0; i < word.length(); i++){
        temp = temp->map[word[i]];
        if (temp == NULL){
            return "";
        }

    }

    // If it is the end of a valid word stored
    // before then return its meaning
    if (temp->isEndOfWord){
        return temp->meaning;
    }

    return "";
}

bool Trie::isEmpty(Trie* root){
    for (int i = 0; i < alphabetSize; i++){
        if (root->map[i])
            return false;
    }

    return true;
}


Trie* Trie::remove(Trie* root, string word, int level = 0){
    if(!root){
        return NULL;
    }

    // If last character of key is being processed
    if (level == word.size()){

        // This node is no more end of word after
        // removal of given key
        if (root->isEndOfWord){
            root->isEndOfWord = false;
        }


        // If given is not prefix of any other word
        if (isEmpty(root)){
            delete (root);
            root = NULL;
        }

        return root;
    }

}


