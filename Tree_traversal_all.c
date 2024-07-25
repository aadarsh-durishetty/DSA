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

void Preorder(struct Create_node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->Content_data);
    Preorder(node->left);
    Preorder(node->right);
}
void Inorder(struct Create_node *node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf("%d ", node->Content_data);
    Inorder(node->right);
}
void Postorder(struct Create_node *node)
{
    if (node == NULL)
        return;
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->Content_data);
}
int main()
{
    struct Create_node *root = newNode(10);
    root->right = newNode(40);
    // root->right->left = newNode(7);
    root->right->right = newNode(50);
    root->left = newNode(1);
    root->left->right = newNode(7);
    // root->left->left = newNode(40)
    // root->left->left->left = newNode(80);

    printf("\nPre-Order traversal of binary tree: \n");
    Preorder(root);
    printf("\nIn-Order traversal of binary tree: \n");
    Inorder(root);
    printf("\nPost-Order traversal of binary tree: \n");
    Postorder(root);
    getchar();
    return 0;
}