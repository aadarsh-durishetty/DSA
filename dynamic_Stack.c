#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int *data;
    int top;
    int size;
} stack;

void push(stack *sp, int value);
int pop(stack *sp);
int peek(stack *sp);

void push(stack *sp, int value)
{
    if (sp->top == sp->size - 1)
    {
        // double size as it is overflow
        int *temp = (int *)malloc(sizeof(int) * sp->size * 2);
        if (temp == "\0")
        {
            printf("error---unable to allocate memory");
            return;
        }
        int i = 0;
        for (int i = 0; i <= sp->top; i++)
        {
            temp[i] = sp->data[i];
        }
        free(sp->data);
        sp->data = temp;
        sp->size *= 2;
    }
    sp->data[++sp->top] = value;
}

int pop(stack *sp)
{
    if (sp->top == -1)
    {
        printf("underflow");
    }
    else
    {
        return sp->data[sp->top];
    }
}
int peek(stack *sp)
{
}

int main(int argc, char const *argv[])
{
}