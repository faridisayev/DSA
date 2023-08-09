#include <iostream>

using namespace std;

void linearSearch(int a[], int n)
{
    int temp = -1;

    for (int i = 0; i < 5; i++)
    {
        if (a[i] == n)
        {
            cout << "Position: " << i << endl;

            temp = 0;
        }
    }

    if (temp == -1)
    {
        cout << "Not found" << endl;
    }
}

int main()
{
    int arr[5] = {1, 22, 34, 5, 7};

    int  num;
    
    cout << "Search: ";

    cin >> num;

    linearSearch(arr, num);


    return 0;
}