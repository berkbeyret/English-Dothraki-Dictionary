#ifndef ASSIGNMENT4_TRIE_H
#define ASSIGNMENT4_TRIE_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int alphabetSize = 26;

struct TrieNode;

class Trie {
    private:
        TrieNode* root = newTrieNode();

    public:

    string getMeaning(Trie *root, const string &word);

    bool isEmpty(Trie *root);

    Trie *remove(Trie *root, string word, int level);

    TrieNode *newTrieNode();

    void insert(string word, string meaning);

    int countChildren(TrieNode *node, int *index);

    string search(string word);

    string deleteWord(string word);
};


#endif //ASSIGNMENT4_TRIE_H
