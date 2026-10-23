// floyd's method 
// finding loop/ cycle in linked list
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
bool hasLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a loop
    fifth->next = third;

    if (hasLoop(head))
    {
        cout << "Loop exists in the linked list." << endl;
    }
    else
    {
        cout << "No loop exists in the linked list." << endl;
    }
    return 0;
}
