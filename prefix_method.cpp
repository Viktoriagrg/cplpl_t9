#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <Windows.h>

#define A  36 // Assuming 36 characters in the alphabet, including special characters

using namespace std;

// Node structure for the Trie
struct treeNode
{
    struct treeNode* children[A];
    char a; // Character stored in the node
    bool isEnd; // Flag to indicate the end of a word
};

// Function to create a new Trie node
treeNode* getNode(void)
{
    treeNode* p = new treeNode;
    p->isEnd = false;

    for (int i = 0; i < A; i++)
        p->children[i] = NULL;

    return p;
}

// Function to insert a word into the Trie
void insert(treeNode* root, string key)
{
    treeNode* p = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index;
        // Handle special characters 'і', 'ї', 'є', 'ґ', '’', '-', '!'
        if (key[i] == 'і') 
        {
            index = 26;
        }
        else if (key[i] == 'ї')
        {
            index = 27;
        }
        else if (key[i] == 'є')
        {
            index = 29;
        }
        else if (key[i] == 'ґ')
        {
            index = 32;
        }
        else if (key[i] == '’')
        {
            index = 33;
        }
        else if (key[i] == '-')
        {
            index = 34;
        }
        else if (key[i] == '!') 
        {
            index = 35;
        }
        else 
        {
            index = key[i] - 'а';
        }

        if (!p->children[index]) 
        {
            p->children[index] = getNode();
        }
        p = p->children[index];
        p->a = key[i];
    }
    p->isEnd = true;
}

// Function to search for a word in the Trie
bool search(treeNode* root, string key)
{
    treeNode* p = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = abs(key[i] + 'а');
        if (!p->children[index])
            return false;

        p = p->children[index];
    }
    return (p->isEnd);
}

// Vector to store search results
static vector<string> a;

// Function to search for words with a given prefix in the Trie
void searchByPrefix(treeNode* trieNode, string k, string prefix, int index) 
{
    if (index < prefix.length()) 
    {
        char ch = prefix[index];
        int position;

        // Handle special characters in the prefix
        if (ch == 'і')
        {
            position = 26;
        }
        else if (ch == 'ї')
        {
            position = 27;
        }
        else if (ch == 'є')
        {
            position = 29;
        }
        else if (ch == 'ї')
        {
            position = 32;
        }
        else if (ch == '’')
        {
            position = 33;
        }
        else if (ch == '-')
        {
            position = 34;
        }
        else if (ch == '!') 
        {
            position = 35;
        }
        else 
        {
            position = ch - 'а';
        }

        if (trieNode->children[position] != nullptr) 
        {
            k += trieNode->children[position]->a;
            if (index == prefix.length() - 1 && trieNode->children[position]->isEnd) 
            {
                a.push_back(k);
            }
            searchByPrefix(trieNode->children[position], k, prefix, index + 1);
            k[k.length() - 1] = NULL; // Clear the last character for backtracking
        }
    }
    else 
    {
        // If the prefix is fully traversed, explore all child nodes
        for (int i = 0; i < A; i++) 
        {
            if (trieNode->children[i] != NULL) 
            {
                k += trieNode->children[i]->a;
                if (trieNode->children[i]->isEnd) 
                {
                    a.push_back(k);
                }
                searchByPrefix(trieNode->children[i], k, prefix, index + 1);
                k[k.length() - 1] = NULL; // Clear the last character for backtracking
            }
        }
    }
}

// Function to delete the Trie
void del(treeNode* p) 
{
    p->isEnd = false;
    for (int i = 0; i < A; i++)
        p->children[i] = NULL;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Using a file-dictionary with words
    ifstream input("q.txt");
    treeNode* root = getNode();
    string line;

    while (input >> line) 
    {
        insert(root, line);
    }

    string k;
    cout << "Enter a prefix: ";
    cin >> k;

    string u;
    searchByPrefix(root, u, k, 0);

    line.erase(line.length());
    del(root);

    cout << endl << "Data is processing" << endl;
    cout << endl << a[0] << endl << a[1] << endl << a[2]; // Displaying some results, adjust as needed
    a.clear();

    return 0;
}
