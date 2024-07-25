#include <stdlib.h>
#include <stdio.h>

struct Create_node
{
    int Content_data;
    struct Create_node *next;
};
struct Create_node *Head_node = NULL;
struct Create_node *sorted_node = NULL;

void push(int Value_data)
{
    struct Create_node *target = (struct Create_node *)malloc(sizeof(struct Create_node *));
    target->Content_data = Value_data;
    target->next = Head_node;
    Head_node = target;
}

void linkedlist(struct Create_node *Head_node)
{
    printf("\nelements present in linked list:\n");
    while (Head_node != NULL)
    {
        printf("%d  ", Head_node->Content_data);
        Head_node = Head_node->next;
    }
}

void insert_at_begin(struct Create_node *Head_node, int Input_data)
{
    struct Create_node *target = (struct Create_node *)malloc(sizeof(struct Create_node *));
    if (target != NULL)
    {
        target->Content_data = Input_data;
        target->next = Head_node;
        Head_node = target;
        printf("\nthe node is inserted/n");
        linkedlist(Head_node);
    }
}

void insert_at_end(struct Create_node *Head_node, int Input_data)
{
    struct Create_node *target = (struct Create_node *)malloc(sizeof(struct Create_node *));
    target->Content_data = Input_data;
    target->next = NULL;
    if (Head_node == NULL)
    {
        Head_node = target;
    }
    else
    {
        struct Create_node *last = Head_node;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = target;
    }
    linkedlist(Head_node);
}

void insert_in_middle(struct Create_node *Head_node, int Input_data)
{
    struct Create_node *target = (struct Create_node *)malloc(sizeof(struct Create_node *));
    struct Create_node *check;
    if (target != NULL)
    {
        target->Content_data = Input_data;
        target->next = NULL;
        check = Head_node;
        for (int counter = 1; counter < 3; counter++)
        {
            check = check->next;
            if (check == NULL)
                break;
        }
        if (check != NULL)
        {
            target->next = check->next;
            check->next = target;
        }
    }
    linkedlist(Head_node);
}

void delete_at_begin(struct Create_node *Head_node)
{
    struct Create_node *target = (struct Create_node *)malloc(sizeof(struct Create_node *));
    if (Head_node != NULL)
    {
        target = Head_node;
        Head_node = target->next;
        free(target);
        printf("\nnode is deleted from the beginning\n");
    }
    linkedlist(Head_node);
}

void delete_at_end(struct Create_node *Head_code)
{
    struct Create_node *target = (struct Create_node *)malloc(sizeof(struct Create_node *));
    struct Create_node *check;
    if (Head_code != NULL)
    {
        target = Head_code;
        while (target->next != NULL)
        {
            check = target;
            target = target->next;
        }
        check->next = NULL;
        free(target);
        printf("\nnode is deleted at the end\n");
    }
    linkedlist(Head_code);
}

void Search(struct Create_node *Head_node)
{
    struct Create_node *target;
    int Input_data, i = 0, flag;
    target = Head_node;
    if (target == NULL)
    {
        printf("\nthe list is empty\n");
    }
    else
    {
        printf("\nenter element to be searched: ");
        scanf("%d", &Input_data);
        while (target != NULL)
        {
            if (target->Content_data == Input_data)
            {
                printf("\nelement is found at the location index %d ", i + 1);
                flag = 0;
            }
            i++;
            target = target->next;
        }
        if (flag != 0)
        {
            printf("\nelement is absent\n");
        }
    }
}

void sortList()
{
    struct Create_node *present_pos = Head_node, *index = NULL;
    int temp;

    if (Head_node != NULL)
    {
        while (present_pos != NULL)
        {
            index = present_pos->next;
            while (index != NULL)
            {
                if (present_pos->Content_data > index->Content_data)
                {
                    temp = present_pos->Content_data;
                    present_pos->Content_data = index->Content_data;
                    index->Content_data = temp;
                }
                index = index->next;
            }
            present_pos = present_pos->next;
        }
    }
}

int main()
{
    int elements[5];
    for (int i = 0; i < 5; i++)
    {
        printf("enter the element %d:  ", i + 1);
        scanf("%d", &elements[i]);
    }
    push(elements[4]);
    push(elements[3]);
    push(elements[2]);
    push(elements[1]);
    push(elements[0]);
    linkedlist(Head_node);
    insert_at_begin(Head_node, 6);
    insert_at_end(Head_node, 7);
    insert_in_middle(Head_node, 8);
    delete_at_begin(Head_node);
    delete_at_end(Head_node);
    Search(Head_node);
    sortList();
    linkedlist(Head_node);
    return 0;
}