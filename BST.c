// C program to demonstrate
// delete operation in binary
// search tree
#include <stdio.h>
#include <stdlib.h>

struct Create_node
{
    int key;
    struct Create_node *left, *right;
};

// A utility function to create a new BST node
struct Create_node *newNode(int item)
{
    struct Create_node *temp = (struct Create_node *)malloc(sizeof(struct Create_node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct Create_node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* A utility function to
insert a new node with given key in
* BST */
struct Create_node *insert(struct Create_node *node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search
tree, return the node
with minimum key value found in
that tree. Note that the
entire tree does not need to be searched. */
struct Create_node *minValueNode(struct Create_node *node)
{
    struct Create_node *current = node;

    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree
and a key, this function
deletes the key and
returns the new root */
struct Create_node *deleteNode(struct Create_node *root, int key)
{
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key,
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct Create_node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Create_node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        struct Create_node *temp = minValueNode(root->right);

        // Copy the inorder
        // successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

struct Create_node *insertion(struct Create_node *root, int x)
{
    if (root == NULL)
        return newNode(x);
    if (x < root->key)
        root->left = insertion(root->left, x);
    else
        root->right = insertion(root->right, x);
    return root;
}

int minValue(struct Create_node *node)
{
    struct Create_node *current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return (current->key);
}

int maxValue(struct Create_node *node)
{
    struct Create_node *current = node;

    /* loop down to find the leftmost leaf */
    while (current->right != NULL)
    {
        current = current->right;
    }
    return (current->key);
}

int main()
{
    struct Create_node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);
    insertion(root, 900);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nMinimum value of BST: \n");
    printf("%d", minValue(root));

    printf("\nMaximum value of BST: \n");
    printf("%d", maxValue(root));

    return 0;
}
