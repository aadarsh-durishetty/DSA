#include <stdio.h>

int top = -1;
int capacity;
int stack[100], choice = 0;

void push()
{
    int val;
    if (top == capacity)
        printf("\n Overflow \n");
    else
    {
        printf("Enter the value: ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop()
{
    if (top == -1)
        printf("Underflow\n");
    else
        top = top - 1;
    printf("%d", stack[top + 1]);
}
void peek()
{
    printf("The peek element is: ");
    if (top != -1)
        printf("%d\n", stack[top]);
    else
        printf("Stack is empty\n");
}
int isFull()
{
    if (top == (capacity - 1))
        printf("The Stack is full\n");
    else
        printf("The Stack is not full\n");
}

int isEmpty()
{
    if (top == -1)
        printf("The Stack is empty\n");
    else
        printf("The Stack is not empty");
}
void show()
{
    printf("The stack data elements are: \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
    if (top == -1)
    {
        printf("Stack is empty");
    }
}

int main()
{

    printf("Enter the number of elements in the stack: ");
    scanf("%d", &capacity);

    while (choice != 6)
    {
        printf("\n1.Push 2.Pop 3.Peek 4.isFull 5.isEmpty 6.show 7.Exit\n");
        printf("\n Enter your choice \n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            peek();
            break;
        }
        case 4:
        {
            isFull();
            break;
        }
        case 5:
        {
            isEmpty();
            break;
        }
        case 6:
        {
            show();
            break;
        }
        case 7:
        {
            printf("Thank you\n");
            break;
        }
        default:
        {
            printf("Please Enter valid choice \n");
        }
        };
    }
    return 0;
}
