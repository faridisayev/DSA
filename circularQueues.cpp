#include <iostream>

using namespace std;

class circularQueue
{
    private:

        int front;
        
        int rear;

        int arr[5];

        int itemCount;

    public:

        circularQueue()
        {
            itemCount = 0;

            front = -1;

            rear = -1;

            for (int i = 0; i < 5; i ++)
            {
                arr[i] = 0;
            }
        }

        bool isEmpty()
        {
            return (front == -1 && rear == -1) ? true : false;
        }

        bool isFull()
        {
            return ((rear + 1) % 5 == front) ? true : false;
        }

        void enqueue(int val)
        {
            if (isFull())
            {
                cout << "Full" << endl;

                return;
            }
            else if (isEmpty())
            {
                front = 0;

                rear = 0;
            }
            else
            {
                rear = (rear + 1) % 5; // update rear
            }

            arr[rear] = val;

            itemCount ++;
        }

        int dequeue()
        {
            int temp = 0;

            if (isEmpty())
            {
                cout << "Empty" << endl;

                return 0;
            }
            else if (front == rear)
            {
                temp = arr[front];

                arr[front] = 0;

                front = -1;

                rear = -1;
            }
            else 
            {
                temp = arr[front];

                arr[front] = 0;

                front = (front + 1) % 5; // update front
            }

            itemCount --;

            return temp;
        }

        int count()
        {
            return itemCount;
        }

        void display()
        {
            cout << "All values in the circularQueue are " << endl;

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
    circularQueue queue;

    int option, value;

    do
    {
        cout << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl;
        cout << endl;
        cout << "Operation: ";
        cin >> option;
        cout << endl;

        switch (option)
        {
            case 1:
                cout << "Enqueue: ";
                cin >> value;

                queue.enqueue(value);
                break;

            case 2:
                cout << "Dequeue" << endl;

                cout << queue.dequeue() << endl;
                break;

            case 3:
                cout << "isEmpty " << endl;

                cout << queue.isEmpty() << endl;
                break;

            case 4:
                cout << "isFull" << endl;

                cout << queue.isFull() << endl;
                break;

            case 5:
                cout << "count" << endl;

                cout << queue.count() << endl;
                break;

            case 6:
                cout << "display" << endl;

                queue.display();
                break;

            case 7:
                system("clear");
                break;

            default:
                cout << "Invalid option" << endl;
        }

    } 
    while (option != 0);
    
    return 0;
}