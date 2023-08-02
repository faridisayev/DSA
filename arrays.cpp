#include <iostream>
#include <string>

using namespace std;

class Stack
{
    private:

        int top;

        int arr[5];

    public:

        Stack()
        {
            top = -1;

            for (int i = 0; i < 5; i++)
            {
                // empty array

                arr[i] = 0;
            }
        }

        // isEmpty

        bool isEmpty()
        {
            return top == -1 ? true : false;
        }

        // isFull

        bool isFull()
        {
            return top == 4 ? true : false;
        }

        // push

        void push(int value)
        {
            if (isFull())
            {
                cout << "stack overflow" << endl;
            }
            else 
            {
                top ++;
                arr[top] = value;
            }
        }

        // pop

        int pop()
        {
            if (isEmpty())
            {
                cout << "stack underflow" << endl;

                return 0;
            }
            else
            {
                int popValue = arr[top];

                arr[top] = 0;

                top --;

                return popValue;
            }
        }

        // count

        int count()
        {
            return top + 1;
        }

        // return peek

        int peek(int pos)
        {
            if (isEmpty())
            {
                cout << "stack underflow" << endl;
                
                return 0;
            }
            else
            {
                return arr[pos];
            }
        }

        // change

        void change(int pos, int val)
        {
            arr[pos] = val;

            cout << "value changed at location " << pos << endl;
        }

        // display

        void display()
        {
            cout << "All values in the Stack are " << endl;

            cout << endl;
            for (int i = 0; i < 5; i ++)
            {
                cout << arr[i] << endl;
            }
            cout << endl;
        }
};

int main()
{
    Stack stack;

    int option, position, value;

    do
    {
        cout << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl;
        cout << endl;
        cout << "Operation: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
            case 1:
                cout << "Push: ";
                cin >> value;

                stack.push(value);
                break;

            case 2:
                cout << "Pop" << endl;

                stack.pop();
                break;

            case 3:
                cout << "isEmpty" << endl;

                cout << stack.isEmpty() << endl;
                break;

            case 4:
                cout << "isFull" << endl;

                cout << stack.isFull() << endl;
                break;

            case 5:
                cout << "peek: ";
                cin >> position;

                cout << stack.peek(position) << endl;
                break;

            case 6:
                cout << "count" << endl;

                cout << stack.count() << endl;
                break;

            case 7:
                cout << "change pos: ";
                cin >> position;
                cout << "change val: ";
                cin >> value;

                stack.change(position, value);
                break;

            case 8:
                cout << "display" << endl;

                stack.display();
                break;

            case 9:
                system("clear");
                break;

            default:
                cout << "Invalid option" << endl;
        }


    } 
    while (option != 0);

    return 0;
}