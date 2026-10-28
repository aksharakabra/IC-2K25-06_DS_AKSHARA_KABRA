#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value)
    {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node* head;

public:

    DoublyLinkedList()
    {
        head = NULL;
    }

    // Insert at beginning
    void insertAtBeginning(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position)
    {
        if (position <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1)
        {
            insertAtBeginning(value);
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;
    }

    // Delete from end
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;

        delete temp;
    }

    // Delete from a specific position
    void deleteFromPosition(int position)
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (position <= 0)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        if (position == 1)
        {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position && temp != NULL; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }

        temp->prev->next = temp->next;

        delete temp;
    }

    // Display from beginning to end
    void displayForward()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Forward: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    // Display from end to beginning
    void displayBackward()
    {
        if (head == NULL)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        cout << "Backward: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtBeginning(20);
    list.insertAtBeginning(10);

    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.insertAtPosition(25, 3);

    list.displayForward();
    list.displayBackward();

    list.deleteFromBeginning();
    list.displayForward();

    list.deleteFromEnd();
    list.displayForward();

    list.deleteFromPosition(2);
    list.displayForward();

    return 0;
}
