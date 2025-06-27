// Leetcode: https://leetcode.com/problems/good-nodes-in-binary-tree/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
    int n_good = 0;
    void DFS(TreeNode* root, int max)
    {
        if(root == nullptr)
            return;
        if(root->val >= max)
        {
            n_good++;
            max = root->val;
        }
        DFS(root->left, max);
        DFS(root->right, max);
        return;
    }
    int goodNodes(TreeNode* root) {
        DFS(root, -10001); //initialize max to -inf(given in constraints)
        return n_good;
    }
};