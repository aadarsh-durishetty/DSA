#include <iostream>
using namespace std;

void Array(int arr[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "enter the element : " << i + 1 << " = ";
        cin >> arr[i];
    }
}

void ArrayOut(int arr[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "the element " << i + 1 << " = " << arr[i] << endl;
    }
}

void Insert(int arr[100], int size)
{
    int pos, ele;
    cout << "Enter the position of insertion: " << endl;
    cin >> pos;
    cout << "Enter the element to be added:  " << endl;
    cin >> ele;

    for (int i = size - 1; i >= (pos - 1); i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = ele;

    for (int i = 0; i <= size; i++)
    {
        cout << "the element " << i + 1 << "=" << arr[i] << endl;
    }
}

void Delete(int arr[100], int size)
{
    int pos;
    cout << "Enter the position of element to be deleted: ";
    cin >> pos;

    if (pos > size + 1)
    {
        cout << "Deletion is not possible" << endl;
    }
    else
    {
        for (int i = pos - 1; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        for (int i = 0; i < size - 1; i++)
        {
            cout << "The element " << i + 1 << "=" << arr[i] << endl;
        }
    }
}

void Update(int arr[100], int size)
{
    int pos, val;
    cout << "Enter the position to be updated: ";
    cin >> pos;
    cout << "Enter the element: ";
    cin >> val;

    for (int i = pos; i < size; i++)
    {
        arr[pos - 1] = val;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "The element " << i + 1 << "=" << arr[i] << endl;
    }
}

void Search(int arr[100], int size)
{
    int val;
    cout << "Enter the element to be searched: ";
    cin >> val;

    for (int i = 0; i < size + 1; i++)
    {
        if (arr[i - 1] == val)
        {
            cout << "Position of element = " << i << endl;
            break;
        }
    }
}

/*
void Reverse(int arr[100], int size)
{
    int temp;
    for (int i = 0; i < (size + 1); i++)
    {
        for (int j = i; j < (size + 1); j++)
        {
            if (arr[i] > arr[j + 1])
            {
                temp = arr[i];
                arr[i] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 1; i <= (size + 1); i++)
    {
        cout << "sorted element " << i << "=" << arr[i] << endl;
    }
}
*/

int main()
{
    int arr1[100], num, len;
    cout << "enter the size of array: ";
    cin >> len;
    Array(arr1, len);
    ArrayOut(arr1, len);
    // Delete(arr1, len);
    // Insert(arr1, len);
    // Update(arr1, len);
    Search(arr1, len);
    // Reverse(arr1, len);
    return 0;
}