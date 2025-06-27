// Leetcode: https://leetcode.com/problems/path-sum-iii/
#include <iostream>

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
    int n_paths=0;
    void DFS(TreeNode* root, long int sum, int targetSum)
    {
        if(root == nullptr)
            return;
        if(sum+root->val == targetSum)
            n_paths++;
        DFS(root->left, sum+root->val, targetSum);
        DFS(root->right, sum+root->val, targetSum);
        return;
    }
    void perform_DFS_on_all_nodes(TreeNode* root, int targetSum)
    {
        if(root == nullptr)
            return;
        DFS(root, 0, targetSum);
        perform_DFS_on_all_nodes(root->left, targetSum);
        perform_DFS_on_all_nodes(root->right, targetSum);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        perform_DFS_on_all_nodes(root, targetSum);
        return n_paths;
    }
};