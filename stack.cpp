/*
#include <iostream>

using namespace std;

class Stack
{
public:
    int top = -1;
    int capacity;
    int *arr;

    void push(int a)
    {
        if (top != (capacity - 1))
        {
            arr[top + 1] = a;
            top++;
        }
        else
        {
            cout << "Stack Overflow" << endl;
        }
    }

    void peek()
    {
        if (top != -1)
            cout << arr[top];
        else
            cout << "The stack is empty" << endl;
    }

    int pop()
    {
        if (top != -1)
        {
            top = top - 1;
            return arr[top + 1];
        }
        else
            return -1;
    }

    int isFull()
    {
        if (top == (capacity - 1))
            return 1;
        else
            return 0;
    }

    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
};

int main()
{
    Stack *st = new Stack();
    st->capacity = 4;
    st->arr = new int[st->capacity];

    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    // st->push(5);
    st->peek();

    cout << st->pop() << endl;
    cout << st->pop() << endl;
    cout << st->isEmpty() << endl;
    cout << st->isFull() << endl;

    return 0;
}

*/

#include <iostream>
using namespace std;
int *a = new int[100];
int t = -1;
void ins(int n)
{
    a[++t] = n;
}
int pop()
{
    return a[t--];
}
int dispt()
{
    return a[t];
}
void disp()
{
    for (int i = t; i >= 0; i--)
        cout << a[i] << " ";
}
void menu()
{
    cout << "\n 1)Push \n 2)Pop \n 3)Display top \n 4)Display whole stack \n 5)Exit \n Enter your choice: ";
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        cout << "\nEnter the number to be pushed: ";
        int n;
        cin >> n;
        ins(n);
        break;
    case 2:
        cout << "\nYour element is: " << pop();
        break;
    case 3:
        cout << "\nTop: " << dispt();
        break;
    case 4:
        cout << "\nThe stack is: ";
        disp();
        break;
    default:
        exit(0);
    }
    menu();
}

main()
{
    menu();
}
