// find the starting node of the loop in the linked list
// by floyds method
#include <iostream>
using namespace std;
// making of node
struct listnode{
  int val;
  listnode *next;
  listnode(int x) : val(x), next(NULL){
  }
};
class solution{
  public:
  listnode *detectCycle(listnode *head){
    if (!head || !head->next){
      return nullptr;
    }
    // slow and fast pointer
    listnode *slow = head;
    listnode *fast = head;
    while (fast != NULL && fast->next != NULL)
{
  // slow one step and fast two step
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast) {
        slow = head;
         while (slow != fast) {
	slow = slow->next;
	fast  = fast->next; 
      }
     return slow;
   }
}
return nullptr; 

  }
};
int main(){
  listnode* head = new listnode(3);
   listnode* node2 = new listnode(30);
   listnode* node3 = new listnode(35);
   listnode* tail = new listnode(33);

  head->next= node2;
  node2->next = node3;
  node3->next = tail;

  tail->next = node2;

  solution solution;
  listnode *cycleStart = solution.detectCycle(head);

  if (cycleStart != nullptr){
    cout<<"cycle detected!!! starts at node with value:"<<cycleStart->val<<endl;
  } else{
    cout<<"no cycle detected"<<endl;
  }
  return 0;
}
