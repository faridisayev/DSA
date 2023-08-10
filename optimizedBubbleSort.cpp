#include <iostream>

using namespace std;

void optimizedBubbleSort (int s[])
{
    int rounds = 0;

    for (int i = 0; i < 5; i ++)
    {
        rounds ++;

        int flag = false;

        for (int j = 0; j < (5 - i - 1); j ++)
        {
            if (s[j] > s[j + 1])
            {
                flag = true;

                int temp = s[j];

                s[j] = s[j + 1];

                s[j + 1] = temp;
            }
        }

        if (flag == false)
        {
            break;
        }
    }

    cout << "Rounds: " << rounds << endl;
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

    optimizedBubbleSort(s);

    cout << "Sorted: ";

    for (int i = 0; i < 5; i ++)
    {
        cout << s[i] << " ";
    }

    cout << endl;

    return 0;
}