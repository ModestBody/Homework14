#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>

using namespace std;

class Trie 
{
private:
    TrieNode* root;

public:
    Trie();
    ~Trie();
    void insert(const string& word);
    bool search(const string& word);
    void autoComplete(const string& prefix);

private:
    void autoCompleteHelper(TrieNode* node, const string& prefix);
};

#endif // TRIE_H
