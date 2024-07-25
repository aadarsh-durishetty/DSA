#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int findMax(struct Create_node *root)
{
    if (root == NULL)
        return INT_MIN;

    int pos = root->Content_data;
    int left_pos = findMax(root->left);
    int right_pos = findMax(root->right);
    if (left_pos > pos)
        pos = left_pos;
    if (right_pos > pos)
        pos = right_pos;
    return pos;
}

int findMin(struct Create_node *root)
{
    if (root == NULL)
        return INT_MAX;

    int pos = root->Content_data;
    int left_pos = findMin(root->left);
    int right_pos = findMin(root->right);
    if (left_pos < pos)
        pos = left_pos;
    if (right_pos < pos)
        pos = right_pos;
    return pos;
}

void Postorder(struct Create_node *node)
{
    if (node == NULL)
        return;
    Postorder(node->left);
    Postorder(node->right);
    printf("%d ", node->Content_data);
}

// struct node *constructTree()
// {
//     int c, v;
//     printf("Enter the value: ");
//     scanf("%d", &v);
//     struct node *root = newNode(v);
//     printf("1) Yes(1)\n2) No(0)\nLeft subtree for %d: ", v);
//     scanf("%d", &c);
//     if (c == 1)
//         root->left = constructTree();
//     printf("1) Yes(1)\n2) No(0)\nRight subtree for %d: ", v);
//     scanf("%d", &c);
//     if (c == 1)
//         root->right = constructTree();
//     return root;
// }

int main(void)
{
    struct Create_node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    // struct node *root = constructTree();
    printf("Post-Order traversal of binary tree: \n");
    Postorder(root);
    printf("\nThe maximum value in BST: %d \n", findMax(root));
    printf("The minimum value in BST: %d \n", findMin(root));
    getchar();
    return 0;
}
