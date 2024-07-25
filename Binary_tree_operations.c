#include <stdio.h>
#include <stdlib.h>

struct Create_node
{
    int Content_data;
    struct Create_node *left;
    struct Create_node *right;
};
struct Create_node *create(int x)
{
    struct Create_node *temp = malloc(sizeof(struct Create_node));
    temp->Content_data = x;
    temp->left = temp->right = NULL;
    return temp;
}

struct Create_node *insertion(struct Create_node *root, int x)
{
    if (root == NULL)
        return create(x);
    if (x < root->Content_data)
        root->left = insertion(root->left, x);
    else
        root->right = insertion(root->right, x);
    return root;
}
struct Create_node *subtreedelete(struct Create_node *root, struct Create_node *q)
{
    if (root->right != NULL)
        root->right = subtreedelete(root->right, q);
    else
    {
        q->Content_data = root->Content_data;
        root = root->left;
        free(root);
    }

    return (root);
}
struct Create_node *deletion(struct Create_node *root, int x)
{
    struct Create_node *delnode;
    if (x < root->Content_data)
        root->left = deletion(root->left, x);
    if (x > root->Content_data)
        root->right = deletion(root->right, x);
    if (x == root->Content_data)
    {
        delnode = root;
        if (delnode->right == NULL)
        {
            root = delnode->left;
            free(delnode);
        }
        if (delnode->left == NULL)
        {
            root = delnode->right;
            free(delnode);
        }
        if (delnode->left != NULL && delnode->right != NULL)
            delnode->left = subtreedelete(delnode->left, delnode);
    }
    return (root);
}
struct Create_node *display(struct Create_node *root, int level)
{
    int i;
    if (root)
    {
        display(root->right, level + 1);
        // printf("\n");
        for (i = 0; i < level; i++)
            // printf(" ");
            printf("%d", root->Content_data);
        display(root->left, level + 1);
    }
    return (0);
}
int main()
{
    struct Create_node *root = NULL;
    root = insertion(root, 45);
    root = insertion(root, 30);
    root = insertion(root, 50);
    root = insertion(root, 25);
    root = insertion(root, 35);
    root = insertion(root, 45);
    root = insertion(root, 60);
    root = insertion(root, 4);

    printf("Binary Search Tree\n");
    display(root, 1);
    // printf("\nDeleting node 25, Binary Search Tree\n");
    /*deletion(root, 25);
    display(root, 1);
    printf("\nInserting node 2, Binary Search Tree\n");
    insertion(root, 2);
    display(root, 1);*/
    return 0;
}