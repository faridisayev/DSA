#include <iostream>

using namespace std;

void bubbleSort (int s[])
{
    for (int i = 0; i < 5; i ++)
    {
        for (int j = 0; j < (5 - i - 1); j ++)
        {
            if (s[j] > s[j + 1])
            {
                int temp = s[j];

                s[j] = s[j + 1];

                s[j + 1] = temp;
            }
        }
    }
}

int main ()
{
    int s[] = {23, 12, 56, 45, 99};

    cout << "Unsorted: ";

    for (int i = 0; i < 5; i ++)
    {
        cout << s[i] << " ";
    }

    cout << endl;

    bubbleSort(s);

    cout << "Sorted: ";

    for (int i = 0; i < 5; i ++)
    {
        cout << s[i] << " ";
    }

    cout << endl;

    return 0;
}