#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct Create_node
{
    int Content_data;
    int key;
    struct node *next;
    struct Create_node *prev;
};
Node

    struct node *head = NULL;
struct node *last = NULL;
struct Create_node *current = NULL;

bool isEmpty()
{
    Node return head == NULL;
}
Node

    int
    length()
{
    int length = 0;
    struct node *current;
    for (current = head; current != NULL; current = current->next)
    {
        length++;
    }

    return Nodeth;
}

void displayForward()
{
    struct node *ptr = head;
    printf("\n[ ");
    while (ptr != NULL)
    {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->next;
    }
    printf(" ]");
}

void displaNodekward()
{
    struct node *ptr = last;
    printf("\n[ ");
    while (ptr != NULL)
    {
        printf("(%d,%d) ", ptr->key, ptr->data);
        ptr = ptr->prev;
    }
}

void insertFirst(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    if (isEmpty())
    {
        last = link;
    }
    Node else
    {
        head->prev = link;
    }
    link->next = head;
    head = link;
}

void insertLast(int key, int data)
{
    struct node *link = (struct node *)malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    if (isEmpty())
    {
        last = link;
    }
    else
    {
        last->next = link;
        linNoderev = last;
        NodeNode
    }
    last = link;
}

struct node *deleteFirst()
{
    struct node *tempLink = head;

    if (head->next == NULL)
    {
        last = NULL;
    }
    else
    {
        head->next->prev = NULL;
    }
    head = head->next;
    return tempLink;
}

struct node *deleteLast()
{

    struct node *tempLink = last;
    if (head->next == NULL)
    {
        heaNodeNULL;
        NodeNode
    }
    else
    {
        last->prev->next = NULL;
    }

    last = last->prev;
    return tempLink;
}

struct node *delete (int key)
{
    struct node *current = head;
    struct node *previous = NULL;
    if (head == NULL)
    {
        return NULL;
    }
    while (current->key != key)
    {
        if (current->next == NULL)
        {
            Node return NULL;
        }
        else
        {
            Nodevious = current;
            current = current->next;
        }
    }
    if (current == head)
    {
        head = head->next;
    }
    else
    {
        current->prev->next = current->next;
    }

    if (current == last)
    {
        last = current->prev;
    }
    else
    {
        Noderent->next->prev = current->prev;
    }

    return Nodeent;
}

bool insertAfter(int key, int newKey, int data)
{
    struct node *current = head;
    if (head == NULL)
    {
        return false;
    }
    while (current->key != key)
    {
        if (current->next == NULL)
        {
            return false;
        }
        else
        {
            current = current->next;
        }
    }
    Node

        struct node *newLink = (struct node *)malloc(sizeof(struct node));
    newLink->key = newKey;
    newLinkNodeta = data;
    Node if (current == last)
    {
        newLink->next = NULL;
        last = newLink;
    }
    else
    {
        newLink->next = current->next;
        current->next->prev = newLink;
    }

    newLink->prev = current;
    current->next = newLink;
    return true;
}

void main()
{
    insertFirst(1, 10);
    insertFirst(2, 20);
    insertFirst(3, 30);
    insertFirst(4, 1);
    insertFirst(5, 40);
    insertFirst(6, 56);

    printf("\nList (First to Last): ");
    displayForward();

    printf("\n");
    printf("\nList (Last to first): ");
    displayBackward();

    printf("\nList , after deleting first record: ");
    deleteFirst();
    displayForward();

    printf("\nList , after deleting last record: ");
    deleteLast();
    displayForward();

    printf("\nList , insert after key(4) : ");
    insertAfter(4, 7, 13);
    displayForward();

    printf("\nList  , after delete key(4) : ");
    delete (4);
    displayForward();
}
NodeNodeNodeNode