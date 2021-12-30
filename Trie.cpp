#include "Trie.h"

struct TrieNode{
    TrieNode *children[alphabetSize];
    bool isEndOfWord;
    string meaning;

};


TrieNode* Trie::newTrieNode(){
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    for(int i = 0; i < alphabetSize; i++){
        node->children[i] = NULL;
    }
    return node;
}

//insert
void Trie::insert(string word, string meaning){

    TrieNode* temp = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';

        // Make a new node if there is no path
        if(!temp -> children[index]){
            temp->children[index] = newTrieNode();
        }
        temp = temp->children[index];
    }

    // Mark end of word and store the meaning
    temp->isEndOfWord = true;
    temp->meaning = meaning;

    cout << '"' + word + '"' + " was added" << endl;
}

string Trie::search(string word){
    TrieNode* temp = root;
    string prefix;

    for (int i = 0; i < word.length(); i++){

        int index = word[i] - 'a';

        if (!root->children[index]){
            return "no record";
        }

        temp = temp->children[index];
        prefix.push_back('a' + index);
    }

    if(temp->isEndOfWord == false){
        return "not enough Dothraki word";
    }

    else if(temp->isEndOfWord == true && word != prefix){
        return "incorrect Dothraki word";
    }

    else if(temp->isEndOfWord == true && word == prefix){
        return "The English equivalent is " + temp->meaning;
    }

}

string Trie::deleteWord(string word, int depth = 0){
    TrieNode* temp = root;
    string prefix;

    for(int i = 0; i < word.length(); i++){
        int index = word[i] - 'a';

        if (!root->children[index]){
            return "no record";
        }

        temp = temp->children[index];
        prefix.push_back('a' + index);
    }

    if(word.size() < prefix.size()){
        return "not enough Dothraki word";
    }

    else if(word.size() == prefix.size() && word != prefix){
        return "incorrect Dothraki word";
    }

    else if(word.size() == prefix.size() && word == prefix){
        temp->isEndOfWord = false;
        temp->meaning = "";
        return '"' + word +  '"' + " deletion is successful";
    };
}

int Trie::countChildren(TrieNode *node, int *index){
    int count = 0;
    for (int i = 0; i < alphabetSize; i++){

        if (node->children[i] != NULL){

            count++;
            *index = i;
        }
    }
    return count;
}





