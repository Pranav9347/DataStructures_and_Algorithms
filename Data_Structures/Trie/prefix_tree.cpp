#include <iostream>
#include <string>
using namespace std;

class TrieNode {
public:
    bool isEndOfWord;
    TrieNode* children[26];
    TrieNode(){
        isEndOfWord = false;
        for(int i=0;i<26;i++)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++)
        {
            if(temp->children[word[i]-'a'] == nullptr)
                temp->children[word[i]-'a'] = new TrieNode();
            temp = temp->children[word[i]-'a'];
        }
        temp->isEndOfWord = true;
    }
    
    bool search(string word, bool prefix=false) {
        TrieNode* temp = root;
        for(int i=0;i<word.size();i++)
        {
            if(temp == nullptr) return false;
            temp = temp->children[word[i]-'a'];
        }
        if(temp == nullptr) return false;
        if(temp->isEndOfWord == true) return true;
        if(prefix) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};

int main()
{
    Trie strings;
    strings.insert("ant");
    strings.insert("and");
    cout <<boolalpha<< strings.search("ant")<<endl;
    cout<< strings.startsWith("an")<<endl;
    cout<< strings.startsWith("b")<<endl;
    return 0;
}