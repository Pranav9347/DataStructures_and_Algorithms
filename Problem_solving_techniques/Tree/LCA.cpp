#include <iostream>
using namespace std;


 // Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* LCA = nullptr;
int min_visited_nodes=100001; //inf
int found, curr;
int DFS(TreeNode* node, int nodes_visited, TreeNode* p, TreeNode* q)
{
    if(node == nullptr)
        return nodes_visited;
    if(node == p || node == q)
        found++;
    int l = DFS(node->left, nodes_visited+1, p, q);
    int r = DFS(node->right, nodes_visited+1, p, q);
    return l+r-(nodes_visited+1);
}
TreeNode* perform_DFS_from_all_nodes(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root == nullptr)
        return nullptr;
    found = 0;
    curr = DFS(root, 0, p, q);
    if(found != 2)
        curr = 100002;
    if(min_visited_nodes > curr)
    {
        min_visited_nodes = curr;
        LCA = root;
    }
    perform_DFS_from_all_nodes(root->left, p, q);
    perform_DFS_from_all_nodes(root->right, p, q);
    return LCA;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return perform_DFS_from_all_nodes(root, p, q);
}


int main()
{
    // Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode* p = root->left;
    TreeNode* q = root->left->right->right;
    cout << lowestCommonAncestor(root, p, q)->val;
    return 0;
}