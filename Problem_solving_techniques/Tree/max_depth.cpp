// Leetcode: https://leetcode.com/problems/max-depth-of-binary-tree/
#include <iostream>
#include <algorithm>
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
    int DFS(TreeNode* root, int depth)
    {
        if(root == nullptr)
            return depth;
        int d_left = DFS(root->left, depth+1);
        int d_right = DFS(root->right, depth+1);
        return max(d_left, d_right);
    }
    int maxDepth(TreeNode* root) {
        return DFS(root, 0);
    }
};