#include <stdio.h>
#include <stdlib.h>

// Data structure to store a binary tree node
struct Create_node
{
    int Content_data;
    struct Create_node *left, *right;
};

// Function to create a new binary tree node having a given key
struct Create_node *newNode(int key)
{
    struct Create_node *node = (struct Create_node *)malloc(sizeof(struct Create_node));
    node->Content_data = key;
    node->left = node->right = NULL;

    return node;
}

// Recursive function to find the k'th smallest node
// in the BST (using inorder traversal)
struct Create_node *kthSmallest(struct Create_node *root, int *counter, int k)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    // recur for the left subtree
    struct Create_node *left = kthSmallest(root->left, counter, k);

    // if k'th smallest node is found
    if (left != NULL)
    {
        return left;
    }

    // if the root is k'th smallest node
    if (++(*counter) == k)
    {
        return root;
    }

    // recur for the right subtree only if k'th smallest node is not found
    // in the right subtree
    return kthSmallest(root->right, counter, k);
}

// Function to find the k'th smallest node in a BST
struct Create_node *findKthSmallest(struct Create_node *root, int k)
{
    // counter to keep track of the total number of the visited nodes
    int counter = 0;

    // recursively find the k'th smallest node
    return kthSmallest(root, &counter, k);
}

int main(void)
{
    /* Construct the following BST
              15
            /    \
           /      \
          10       20
         /  \     /  \
        /    \   /    \
       8     12 16    25
    */

    struct Create_node *root = newNode(15);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);

    int k = 4;

    // find the k'th smallest node
    struct Create_node *result = findKthSmallest(root, k);

    if (result)
    {
        printf("%d'th smallest node is %d", k, result->Content_data);
    }
    else
    {
        printf("%d'th smallest node does not exist.", k);
    }

    return 0;
}