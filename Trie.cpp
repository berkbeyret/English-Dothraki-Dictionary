#include "Trie.h"

vector<string> insertKeys; //inserted words for check

struct TrieNode{
    TrieNode *children[alphabetSize];
    bool isEndOfWord;
    string meaning;
};

TrieNode* Trie::newTrieNode(){ // create node
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    for(int i = 0; i < alphabetSize; i++){
        node->children[i] = NULL;
    }
    return node;
}

void Trie::insert(string word, string meaning){

    TrieNode* temp = root;
    for (int i = 0; i < word.length(); i++) {
        int index = word[i] - 'a';

        // create new node if there isn't any path
        if(!temp -> children[index]){
            temp->children[index] = newTrieNode();
        }
        temp = temp->children[index];
    }

    if (!count(insertKeys.begin(), insertKeys.end(), word)) {
        cout << '"' + word + '"' + " was added" << endl;
        insertKeys.push_back(word);
    }
    else {
        if(temp->meaning == meaning){
            cout << '"' + word + '"' + " already exist" << endl;
        }
        else{
            cout << '"' + word + '"' + " was updated" << endl;
        }
    }

    //This is end of the word and we're storing the meaning

    temp->isEndOfWord = true;
    temp->meaning = meaning;
}

string Trie::search(string word){
    TrieNode* temp = root;
    string prefix;

    for (int i = 0; i < word.length(); i++){

        int index = word[i] - 'a';
        int firstIndex = word[0] - 'a';

        if (!temp->children[index]){
            if(!root->children[firstIndex]){
                return "no record";
            }
            else{
                return "incorrect Dothraki word";
            }
        }
        temp = temp->children[index];
        prefix.push_back('a' + index);
    }

    if(temp->isEndOfWord == false){
        return "not enough Dothraki word";
    }

    else if(temp->isEndOfWord == true && word == prefix){
        return "The English equivalent is " + temp->meaning;
    }

}

string Trie::deleteWord(string word){
    TrieNode* temp = root;
    string prefix;
    int index;

    for(int i = 0; i < word.length(); i++){
        int index = word[i] - 'a';
        int firstIndex = word[0] - 'a';

        if (!temp->children[index]){
            if(!root->children[firstIndex]){
                return "no record";
            }
            else{
                return "incorrect Dothraki word"; //node has no leaf and word and prefix are not same
            }
        }

        temp = temp->children[index];
        prefix.push_back('a' + index);
    }

    if(countChildren(temp,&index) > 0 && temp->isEndOfWord == false){ //node has leaf and node isn't on the end of the word
        return "not enough Dothraki word";
    }

    else if(word.size() == prefix.size() && word == prefix){ //makes the end of the word false and deletes the meaning
        temp->isEndOfWord = false;
        temp->meaning = "";
        return '"' + word +  '"' + " deletion is successful";
    };
}


int Trie::countChildren(TrieNode *node, int *index){ //return the integer how many children the node has
    int count = 0;
    for (int i = 0; i < alphabetSize; i++){

        if (node->children[i] != NULL){

            count++;
            *index = i;
        }
    }
    return count;
}





