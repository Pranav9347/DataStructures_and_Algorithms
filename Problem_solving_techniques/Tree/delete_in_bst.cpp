// LeetCode Problem: https://leetcode.com/problems/delete-node-in-a-bst/

#include <iostream>
using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        // Helper: Finds the inorder successor of the given node and updates successorParent.
        TreeNode* inorder_successor(TreeNode* target, TreeNode*& successorParent) {
            successorParent = target;  // Reset the parent pointer.
            target = target->right;    // Move to right child.
            while (target && target->left) {
                successorParent = target;
                target = target->left;
            }
            return target;
        }
        
        TreeNode* deleteNode(TreeNode* root, int key) {
            if (!root) return nullptr;
            TreeNode* parent = nullptr;
            TreeNode* node = root;
            
            // Find the node to delete and its parent.
            while (node && node->val != key) {
                parent = node;
                if (key < node->val)
                    node = node->left;
                else
                    node = node->right;
            }
            
            // If the key is not found, return original tree.
            if (!node) return root;
            
            // If node has two children.
            if (node->left && node->right) {
                TreeNode* successorParent = nullptr;
                TreeNode* successor = inorder_successor(node, successorParent);
                node->val = successor->val;  // Copy successor's value into current node.
                // Now, set node to successor to remove it.
                parent = successorParent;
                node = successor;
            }
            
            // Node now has at most one child.
            TreeNode* child = (node->left) ? node->left : node->right;
            
            // If we're deleting the root.
            if (!parent) {
                delete node;
                return child;
            }
            else if (parent->left == node)
                parent->left = child;
            else
                parent->right = child;
            
            delete node;
            return root;
        }
    };