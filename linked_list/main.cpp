#include <iostream>

using namespace std;

int main()
{

    struct Node
    {
        int data;
        Node *next;

        Node(int value) : data(value), next(nullptr) {};
    };

    class LinkedList
    {
    private:
        Node *head;

    public:
        LinkedList() : head(nullptr) {}

        // Insert at head : O(1)
        void insertAtHead(int val)
        {
            Node *newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        };

        // Insert at end : O(n)
        void insertAtTail(int val)
        {
            Node *newNode = new Node(val);

            if (!head)
            {
                head = newNode;
                return;
            }

            Node *current = head;
            while (current->next)
            {
                current = current->next;
            };
            current->next = newNode;
        };

        // Delete node : O(n)
        void deleteNode(int key)
        {
            if (!head)
                return;
            if (head->data == key)
            {
                Node *current = head;
                head = head->next;
                delete current;
                return;
            }

            Node *current = head;
            while (current->next && current->next->data != key)
            {
                current = current->next;
            };

            if (!current->next)
                return;

            Node *toBeDelete = current->next;
            current->next = current->next->next;
            delete toBeDelete;
            return;
        };

        bool search(int key)
        {
            Node *current = head;
            while (current)
            {
                if (current->data == key)
                {
                    return true;
                }
                current = current->next;
            };
            return false;
        };

        void display()
        {
            Node *current = head;

            while (current)
            {
                cout << "Printing each Node " << current->data << endl;
                current = current->next;
            }
            return;
        };

        ~LinkedList(){
            Node* current;
            while (head)
            {
                current = head;
                head = head->next;
                delete current;
            }
            
        };
    };

    LinkedList list;
    list.insertAtHead(5);
    list.insertAtHead(6);
    list.insertAtTail(7);
    list.insertAtHead(8);
    list.deleteNode(7);
    list.display();

    return 0;
}