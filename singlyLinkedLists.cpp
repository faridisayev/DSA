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

class SinglyLinkedList
{
    public:

        Node* head;

        SinglyLinkedList ()
        {
            head = NULL;
        }

        SinglyLinkedList (Node *n)
        {
            head = n;
        }

        // Check if node exists

        Node* nodeExists (int k)
        {
            Node* temp = NULL;

            Node* ptr = head;

            while (ptr != NULL)
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }

                ptr = ptr->next;
            }

            return temp;
        }

        // Append node

        void appendNode(Node *n)
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
                }
                else
                {
                    Node* ptr = head;

                    while (ptr->next != NULL)
                    {   
                        ptr = ptr->next;
                    }

                    ptr->next = n;
                }

                cout << "Appended" << endl;
            }
        }

        // Prepend node

        void prependNode(Node* n)
        {
            if (nodeExists(n->key) != NULL)
            {
                cout << "Exists" << endl;
            }
            else
            {
                n->next = head;
                
                head = n;

                cout << "Prepended" << endl;
            }
        }

        // Insert node

        void insertNode(int k, Node *n)
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
                    n->next = ptr->next;

                    ptr->next = n;
                }
            }
        }

        // Delete node

        void deleteNode(int k)
        {
            if (head == NULL)
            {
                cout << "Empty" << endl;
            }
            else
            {
                if (head->key == k)
                {
                    head = head->next;

                    cout << "Unlinked" << endl;
                }
                else
                {
                    Node* temp = NULL;

                    Node* prevptr = head;

                    Node* currentptr = head->next;

                    while (currentptr != NULL)
                    {
                        if (currentptr->key == k)
                        {
                            temp = currentptr;

                            currentptr = NULL;
                        }
                        else
                        {
                            prevptr = prevptr->next;

                            currentptr = currentptr->next;
                        }
                    }

                    if (temp != NULL)
                    {
                        prevptr->next = temp->next;

                        cout << "Unlinked" << endl;
                    }
                    else
                    {
                        cout << "Does not exist" << endl;
                    }
                }
            }
        }

        // Update node

        void updateNode(int k, int d)
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

        // Print node

        void printList()
        {
            if (head == NULL)
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << endl << "Values: ";
                
                Node* temp = head;

                std::string end;

                while (temp != NULL)
                {
                    end = (temp->next == NULL) ? " --> NULL" : " --> ";
                    
                    cout << "(" << temp->key << "," << temp->data << ")" << end;

                    temp = temp->next;
                }

                cout << endl;
            }
        }
};

int main()
{
    SinglyLinkedList s;

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
        cout << "6. print()" << endl;
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