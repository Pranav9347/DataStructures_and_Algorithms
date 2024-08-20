#include<stdio.h>
#include<stdlib.h>
typedef struct Bst_node
{
    int val;
    struct Bst_node* left;
    struct Bst_node* right;
}Bst_node;

void inorder(Bst_node* root) //left->root->right
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
}
void preorder(Bst_node* root) //root->left->right
{
    if(root == NULL)
        return;
    printf("%d ",root->val);
    preorder(root->left);
    preorder(root->right);
}
void postorder(Bst_node* root) //left->right->root
{
    if(root == NULL)
        return;
    postorder(root->left); 
    postorder(root->right);
    printf("%d ",root->val);
}
Bst_node* insert(Bst_node* root, int val)
{
    if(root == NULL)
    {
        root = (Bst_node*)malloc(sizeof(Bst_node));
        root->val = val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(val > root->val)
        root->right = insert(root->right, val);
    else if(val < root->val)
        root->left = insert(root->left, val);
    else return root;
    return root;
}

Bst_node* search(Bst_node* root, int val)
{
    if(root == NULL)
        return root;
    else if(val>root->val)
        return search(root->right, val);
    else if(val<root->val)
        return search(root->left, val);
    else return root;
}

Bst_node* delete(Bst_node* root, int val)//hard
{
    
}

int main()
{
    Bst_node* root = (Bst_node*)malloc(sizeof(Bst_node));
    root->val = 5;
    root->left = (Bst_node*)malloc(sizeof(Bst_node));
    root->left->val = 1;
    root->right = (Bst_node*)malloc(sizeof(Bst_node));
    root->right->val = 8;
    root->left->left = (Bst_node*)malloc(sizeof(Bst_node));
    root->left->left->val = -5;
    root->left->right = (Bst_node*)malloc(sizeof(Bst_node));
    root->left->right->val = 3;
    root->right->left = (Bst_node*)malloc(sizeof(Bst_node));
    root->right->left->val = 7;
    root->right->right = (Bst_node*)malloc(sizeof(Bst_node));
    root->right->right->val = 11;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
    insert(root, 9);
    insert(root, 6);
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    if(search(root, -5) != NULL)
    {
        printf("present in the BST!\n");
    }
    else printf("Not present in the BST\n");
    delete(root, 9);
    delete(root, 6);
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    return 0;
}