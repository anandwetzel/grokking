/*
Given the head of a Singly LinkedList and a number ‘k’, 
rotate the LinkedList to the right by ‘k’ nodes.

Example 1:
  k = 3
  original list = head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null
  new list =      head -> 6 -> 7 -> 8 -> 1 -> 2 -> 3 -> 4 -> 5 -> null
Example 2:
  k = 8
  original list = head -> 1 -> 2 -> 3 -> 4 -> 5 -> null
  new list =      head -> 3 -> 4 -> 5 -> 1 -> 2 -> null
*/

#include <iostream>
using namespace std;

class ListNode {
 public:
  int value = 0;
  ListNode *next;

  ListNode(int value) {
    this->value = value;
    next = nullptr;
  }
};

class RotateList {
  public:
    static ListNode *rotate(ListNode *head, int rotations) {
      if(head == nullptr || head->next == nullptr || rotations <= 1) return head;
      ListNode *lastNode = head;
      int length = 1;
      while(lastNode->next != nullptr){
        lastNode = lastNode->next;
        length++;
      }
      lastNode->next = head;
      rotations %= length;
      length = length - rotations - 1;
      ListNode *lastOfRotated = head;
      for(int i = 0; i < length; ++i){
        lastOfRotated = lastOfRotated->next;
      }
      head = lastOfRotated->next;
      lastOfRotated->next = nullptr;
      return head;
    }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  ListNode *result = RotateList::rotate(head, 3);
  cout << "Nodes of the reversed LinkedList are: ";
  while (result != nullptr) {
    cout << result->value << " ";
    result = result->next;
  }
}

/*
Time Complexity is O(N)
Space Complexity is O(1)
*/