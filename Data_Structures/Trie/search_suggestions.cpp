#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
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

    vector<string> top_suggestions(string prefix) {
    vector<string> res;

    // Step 1: Traverse to the prefix node
    TrieNode* temp = root;
    for (char c : prefix) {
        if (!temp->children[c - 'a']) return res; // prefix doesn't exist
        temp = temp->children[c - 'a'];
    }

    // Step 2: DFS from the prefix node to find up to 3 suggestions
    stack<pair<TrieNode*, string>> st;
    st.push({temp, prefix});

    while (!st.empty() && res.size() < 3) {
        auto [node, currStr] = st.top();
        st.pop();

        if (node->isEndOfWord) {
            res.push_back(currStr);
        }

        // Push children in reverse order so we process 'a' to 'z' when popping
        for (int i = 25; i >= 0; --i) {
            if (node->children[i]) {
                char nextChar = 'a' + i;
                st.push({node->children[i], currStr + nextChar});
            }
        }
    }

    return res;
}

};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> res;
        sort(products.begin(),products.end());
        Trie strings;
        for(string word: products)
            strings.insert(word);
        for(int i=1;i<=searchWord.size();i++)
        {
            string prefix = searchWord.substr(0,i);
            res.push_back(strings.top_suggestions(prefix));
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
    vector<vector<string>> v = S.suggestedProducts(products, "mouse");
    for(vector<string> list: v)
    {
        for(string s: list)
            cout<< s << " ";
        cout<<endl;
    }
    return 0;
}