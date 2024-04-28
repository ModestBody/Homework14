#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>

using namespace std;

struct TrieNode 
{
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode();
};

#endif // TRIENODE_H


