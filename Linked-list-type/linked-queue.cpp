#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Queue
{
private:
    Node* front;
    Node* rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value)
    {
        Node* newNode = new Node(value);

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted into queue." << endl;
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue Underflow." << endl;
            return;
        }

        Node* temp = front;

        cout << temp->data << " deleted from queue." << endl;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    void peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Front element: " << front->data << endl;
    }

    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;

        cout << "Queue: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.peek();

    q.dequeue();

    q.display();

    return 0;
}
