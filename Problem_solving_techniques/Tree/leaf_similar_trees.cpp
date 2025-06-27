// Leetcode: https://leetcode.com/problems/leaf-similar-trees/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void DFS(TreeNode* root, vector<int>& leaf_sequence)
    {
        if(root == nullptr)
            return;
        if(root->left == nullptr && root->right == nullptr)
        {
            leaf_sequence.push_back(root->val);
            return;
        }
        DFS(root->left, leaf_sequence);
        DFS(root->right, leaf_sequence);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf_sequence1, leaf_sequence2;
        DFS(root1, leaf_sequence1);
        DFS(root2, leaf_sequence2);
        if(leaf_sequence1 == leaf_sequence2)
            return true;
        else return false;
    }
};