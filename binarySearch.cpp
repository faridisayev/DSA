#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{

    while (left <= right)
    {
        int mid = left + (right - left)/2;

        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main()
{
    int x = 98;

    int arr[] = {1, 23, 43, 46, 75, 80, 98, 101, 123, 143};

    int output;

    output = binarySearch(arr, 0, 9, x);

    if (output == -1)
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << output << endl;
    }

    return 0;
}