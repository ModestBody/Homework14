#include "Trie.h"
#include <iostream>

using namespace std;

Trie::Trie() 
{
    root = new TrieNode();
}

Trie::~Trie() 
{
    // Implement destructor to free memory
}

void Trie::insert(const string& word) 
{
    TrieNode* curr = root;
    for (char c : word) 
    {
        if (curr->children.find(c) == curr->children.end()) 
        {
            curr->children[c] = new TrieNode();
        }
        curr = curr->children[c];
    }
    curr->isEndOfWord = true;
}

bool Trie::search(const string& word) 
{
    TrieNode* curr = root;
    for (char c : word) 
    {
        if (curr->children.find(c) == curr->children.end()) 
        {
            return false;
        }
        curr = curr->children[c];
    }
    return curr != nullptr && curr->isEndOfWord;
}

void Trie::autoComplete(const string& prefix)
{
    TrieNode* curr = root;
    for (char c : prefix) {
        if (curr->children.find(c) == curr->children.end()) 
        {
            cout << "There are no words starting with this prefix." << endl;
            return;
        }
        curr = curr->children[c];
    }
    autoCompleteHelper(curr, prefix);
}

void Trie::autoCompleteHelper(TrieNode* node, const string& prefix) 
{
    if (node->isEndOfWord) 
    {
        cout << prefix << endl;
    }
    for (auto& child : node->children) 
    {
        autoCompleteHelper(child.second, prefix + child.first);
    }
}
