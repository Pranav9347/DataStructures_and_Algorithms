// Leetcode: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
#include <iostream>
#include <algorithm>
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
    int max_path = 0;
    int zig_zag(TreeNode* node, int pathlen, char dir)
    {
        if(node == nullptr)
            return pathlen;
        if(dir == 'r')
            return zig_zag(node->right, pathlen+1, 'l');
        else
            return zig_zag(node->left, pathlen+1, 'r');
    }
    int node_max_zig_zag(TreeNode* node)
    {
        return max(zig_zag(node->left,0,'r'), zig_zag(node->right,0,'l'));
    }
    int perform_zigZag_on_all_nodes(TreeNode* root)
    {
        int temp;
        if(root == nullptr)
            return 0;
        temp = node_max_zig_zag(root);
        if(max_path<temp)
            max_path=temp;
        perform_zigZag_on_all_nodes(root->left);
        perform_zigZag_on_all_nodes(root->right);
        return max_path;
    }
    int longestZigZag(TreeNode* root) {
        perform_zigZag_on_all_nodes(root);
        return max_path;
    }
};