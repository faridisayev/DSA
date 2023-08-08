#include <iostream>

using namespace std;

class Node
{
    public:

        int key;

        int data;

        Node* next;

        Node ()
        {
            key = 0;

            data = 0;

            next = NULL;
        }

        Node (int k, int d)
        {
            key = k;

            data = d;
        }       
};

class CircularLinkedList
{
    public:

        Node* head;

        CircularLinkedList ()
        {
            head = NULL;
        }

        // Check if node exists

        Node* nodeExists (int k)
        {
            Node* temp = NULL;

            Node* ptr = head;

            if (ptr == NULL)
            {
                return temp;
            }
            else
            {
                do
                {
                    if (ptr->key == k)
                    {
                        temp = ptr;
                    }

                    ptr = ptr->next;
                }
                while (ptr != head);
            
                return temp;
            }
        }

        // Append

        void appendNode (Node* n)
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Exists" << endl;
            }
            else
            {
                if (head == NULL)
                {
                    head = n;

                    n->next = head;
                }
                else
                {
                    Node* ptr = head;

                    while (ptr->next != head)
                    {
                        ptr = ptr->next;
                    }

                    ptr->next = n;

                    n->next = head;
                }

                cout << "Appended" << endl;
            }
        }

        // Prepend

        void prependNode (Node* n)
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Exists" << endl;
            }
            else
            {
                Node* ptr = head;

                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }

                ptr->next = n;

                n->next = head;

                head = n;

                cout << "Prepended" << endl;
            }
        }

        // Insert

        void insertNode (int k, Node* n)
        {
            Node* ptr = nodeExists(k);

            if (ptr == NULL)
            {
                cout << "Does not exist" << endl;
            }
            else
            {
                if (nodeExists(n->key) != NULL)
                {
                    cout << "Exists" << endl;
                }
                else
                {
                    if (ptr->next == head)
                    {
                        n->next = head;

                        ptr->next = n;
                    }
                    else
                    {
                        n->next = ptr->next;

                        ptr->next = n;
                    }

                    cout << "Inserted" << endl;
                }
            }
        }

        // Delete

        void deleteNode (int k)
        {
            Node* ptr = nodeExists(k);

            if (ptr == NULL)
            {
                cout << "Does not exist" << endl;
            }
            else
            {
                if (ptr == head)
                {
                    if (head->next == NULL)
                    {
                        head = NULL;
                    }
                    else
                    {
                        Node* ptr = head;

                        while (ptr->next != head)
                        {
                            ptr = ptr->next;
                        }

                        ptr->next = head->next;

                        head = head->next;
                    }
                }
                else
                {
                    Node* temp = NULL;

                    Node* previous = head;

                    Node* current = head->next;

                    while (current != NULL)
                    {
                        if (current->key == k)
                        {
                            temp = current;

                            current = NULL;
                        }
                        else
                        {
                            previous = previous->next;

                            current = current->next;
                        }
                    }

                    previous->next = temp->next;
                }

                cout << "Unlinked" << endl;
            }
        }

        // Update

        void updateNode (int k, int d)
        {
            Node* ptr = nodeExists(k);

            if (ptr != NULL)
            {
                ptr->data = d;

                cout << "Updated" << endl;
            }
            else
            {
                cout << "Does not exist" << endl;
            }
        }

        // Print

        void printList()
        {
            if (head == NULL)
            {
                cout << "Does not exist" << endl;
            }
            else
            {
                cout << endl << "Head: " << head << endl;

                cout << "Values: " << endl;

                Node* temp = head;

                std::string end;

                do
                {
                    end = (temp->next == head) ? " --> BACK TO HEAD" : " --> ";

                    cout << "(" << temp->key << "," << temp->data << "," << temp->next << ")" << end;

                    temp = temp->next;
                }
                while (temp != head);

                cout << endl;
            }
        }


};

int main()
{
    CircularLinkedList s;

    int option;

    int key1, k1, data1;

    do
    {
        cout << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNode()" << endl;
        cout << "4. deleteNode()" << endl;
        cout << "5. updateNode()" << endl;
        cout << "6. printList()" << endl;
        cout << "7. Clear Screen" << endl;
        cout << endl;
        cout << "Operation: ";
        cin >> option;
        cout << endl;

        Node* n1 = new Node();

        switch (option)
        {
            case 1:
                cout << "appendNode key: ";

                cin >> key1;

                cout << "appendNode data: ";

                cin >> data1;

                n1->key = key1;

                n1->data = data1;

                s.appendNode(n1);

                break;

            case 2:
                cout << "prependNode key: ";
                
                cin >> key1;

                cout << "prependNode data: ";

                cin >> data1;

                n1->key = key1;

                n1->data = data1;

                s.prependNode(n1);

                break;

            case 3:
                cout << "insertNode position: ";

                cin >> k1;

                cout << "insertNode key: ";

                cin >> key1;

                cout << "insertNode data: ";

                cin >> data1;

                n1->key = key1;

                n1->data = data1;

                s.insertNode(k1, n1);

                break;

            case 4:
                cout << "deleteNode key: ";

                cin >> k1;

                s.deleteNode(k1);

                break;

            case 5:
                cout << "updateNode key: ";

                cin >> key1;

                cout << "updateNode data: ";

                cin >> data1;

                s.updateNode(key1, data1);

                break;

            case 6:
                s.printList();
                
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