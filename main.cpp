#include "Trie.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
{
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apply");
    trie.insert("banana");
    trie.insert("ball");
    trie.insert("bat");
    trie.insert("Maksim");
    trie.insert("Bogdan");
    trie.insert("car");
    trie.insert("Mercedes");
    trie.insert("Porsche");
    trie.insert("Volkswagen");
    trie.insert("Lamborghini");

    while (true) 
    {
        cout << "Enter the prefix for auto-completion (to exit, enter 'exit'): ";
        string prefix;
        cin >> prefix;

        if (prefix == "exit") 
        {
            break;
        }

        cout << "Suitable word variants:" << endl;
        trie.autoComplete(prefix);
    }

    return 0;
}
