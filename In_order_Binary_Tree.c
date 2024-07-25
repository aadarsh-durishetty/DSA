#include <stdio.h>
#include <stdlib.h>

struct Create_node
{
    int Content_data;
    struct Create_node *left;
    struct Create_node *right;
};

struct Create_node *newNode(int data)
{
    struct Create_node *node = (struct Create_node *)malloc(sizeof(struct Create_node));
    node->Content_data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void Inorder(struct Create_node *node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("%d ", node->Content_data);
    Inorder(node->right);
}
int main()
{
    struct Create_node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("In-Order traversal of binary tree: \n");
    Inorder(root);
    getchar();
    return 0;
}