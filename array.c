#include <stdio.h>

void array(int arr[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void arrayOut(int arr[100], int size)
{
    printf("The output array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void Search(int arr[100], int size)
{
    int val;
    printf("Enter the element to be searched: ");
    scanf("%d", &val);
    for (int i = 0; i <= size; i++)
    {
        if (arr[i - 1] == val)
        {
            printf("%d", i);
        }
    }
}

void Insert(int arr[100], int size)
{
    int pos, val;
    printf("Enter the element to be inserted: ");
    scanf("%d", &val);
    printf("Enter the position to be inserted: ");
    scanf("%d", &pos);
    for (int i = size - 1; i >= pos - 1; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos - 1] = val;
    for (int i = 0; i < size + 1; i++)
    {
        printf("%d", arr[i]);
    }
}

void Delete(int arr[100], int size)
{
    int pos;
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    for (int i = pos - 1; i >= size - 1; i--)
    {
        arr[i] = arr[i + 1];
    }
    for (int i = 0; i < size - 1; i++)
    {
        printf("%d", arr[i]);
    }
}

void Update(int arr[100], int size)
{
    int pos, val;
    printf("Enter the position to be updated: ");
    scanf("%d", &pos);
    printf("Enter the value to be updated: ");
    scanf("%d", &val);

    for (int i = pos; i < size; i++)
    {
        arr[pos - 1] = val;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}

void Sort(int arr[100], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("The sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}

int main()
{
    int arr[100], len;
    printf("Enter the size of array: ");
    scanf("%d", &len);
    array(arr, len);
    arrayOut(arr, len);
    // Search(arr, len);
    // Insert(arr, len);
    // Delete(arr, len);
    // Update(arr, len);
    Sort(arr, len);
}
