#include <stdio.h>
#include <stdlib.h>
struct Create_node
{
    int Content_data;
    struct Create_node *next;
};
struct Create_node *Head_node;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice = 0;
    while (choice != 7)
    {
        printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from last\n5.Search for an element\n6.Show\n7.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d/n", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            begin_delete();
            break;
        case 4:
            last_delete();
            break;
        case 5:
            search();
            break;
        case 6:
            display();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
}
void beginsert()
{
    struct Create_node *ptr, *temp;
    int item;
    ptr = (struct Create_node *)malloc(sizeof(struct Create_node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("Enter the node data: ");
        scanf("%d", &item);
        ptr->Content_data = item;
        if (Head_node == NULL)
        {
            Head_node = ptr;
            ptr->next = Head_node;
        }
        else
        {
            temp = Head_node;
            while (temp->next != Head_node)
                temp = temp->next;
            ptr->next = Head_node;
            temp->next = ptr;
            Head_node = ptr;
        }
        printf("node inserted\n");
    }
}
void lastinsert()
{
    struct Create_node *ptr, *temp;
    int item;
    ptr = (struct Create_node *)malloc(sizeof(struct Create_node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nEnter Data: ");
        scanf("%d", &item);
        ptr->Content_data = item;
        if (Head_node == NULL)
        {
            Head_node = ptr;
            ptr->next = Head_node;
        }
        else
        {
            temp = Head_node;
            while (temp->next != Head_node)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = Head_node;
        }

        printf("\nnode inserted\n");
    }
}

void begin_delete()
{
    struct Create_node *ptr;
    if (Head_node == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (Head_node->next == Head_node)
    {
        Head_node = NULL;
        free(Head_node);
        printf("\nnode deleted\n");
    }

    else
    {
        ptr = Head_node;
        while (ptr->next != Head_node)
            ptr = ptr->next;
        ptr->next = Head_node->next;
        free(Head_node);
        Head_node = ptr->next;
        printf("\nnode deleted\n");
    }
}
void last_delete()
{
    struct Create_node *ptr, *preptr;
    if (Head_node == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (Head_node->next == Head_node)
    {
        Head_node = NULL;
        free(Head_node);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = Head_node;
        while (ptr->next != Head_node)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nnode deleted\n");
    }
}

void search()
{
    struct Create_node *ptr;
    int item, i = 0, flag = 1;
    ptr = Head_node;
    if (ptr == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        printf("\nEnter item which you want to search: ");
        scanf("%d", &item);
        if (Head_node->Content_data == item)
        {
            printf("item found at location %d", i + 1);
            flag = 0;
        }
        else
        {
            while (ptr->next != Head_node)
            {
                if (ptr->Content_data == item)
                {
                    printf("item found at location %d ", i + 1);
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if (flag != 0)
        {
            printf("Item not found\n");
        }
    }
}

void display()
{
    struct Create_node *ptr;
    ptr = Head_node;
    if (Head_node == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("The elements in List are:\n");

        while (ptr->next != Head_node)
        {

            printf("%d ", ptr->Content_data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->Content_data);
    }
}