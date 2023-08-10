#include <iostream>

using namespace std;

void insertionSort (int arr[])
{
    int j = 0;

    int key = 0;

    for (int i = 1; i < 5; i ++)
    {
        key = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];

            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

int main()
{
    int arr[] = {65, 5, 89, 90, 43};

    cout << "Unsorted: ";

    for (int i = 0; i < 5; i ++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    insertionSort(arr);

    cout << "Sorted: ";

    for (int i = 0; i < 5; i ++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}