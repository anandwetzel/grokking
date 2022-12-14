/*
Given the head of a Singly LinkedList, write a 
method to modify the LinkedList such that the nodes 
from the second half of the LinkedList are inserted 
alternately to the nodes from the first half in 
reverse order. So if the LinkedList has nodes 
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null, 
your method should return 
1 -> 6 -> 2 -> 5 -> 3 -> 4 -> null.

Your algorithm should not use any extra space and 
the input LinkedList should be modified in-place.

Example 1:
    Input: 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> null
    Output: 2 -> 12 -> 4 -> 10 -> 6 -> 8 -> null 
Example 2:
    Input: 2 -> 4 -> 6 -> 8 -> 10 -> null
    Output: 2 -> 10 -> 4 -> 8 -> 6 -> null
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

class RearrangeList {
 public:
  static void reorder(ListNode *head) {
    if(head == nullptr || head->next == nullptr){
      return;
    }
    ListNode *slow = head, *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *headSecond = reverse(slow);
    ListNode *headFirst = head;
    
    while(headFirst != nullptr && headSecond != nullptr){
      ListNode *temp = headFirst->next;
      headFirst->next = headSecond;
      headFirst = temp;

      temp = headSecond->next;
      headSecond->next = headFirst;
      headSecond = temp;
    }

    if (headFirst != nullptr) {
      headFirst->next = nullptr;
    }

  }
 private:
  static ListNode *reverse(ListNode *head){
    ListNode *prev = nullptr;
    while(head != nullptr){
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};

int main(int argc, char *argv[]) {
  ListNode *head = new ListNode(2);
  head->next = new ListNode(4);
  head->next->next = new ListNode(6);
  head->next->next->next = new ListNode(8);
  head->next->next->next->next = new ListNode(10);
  head->next->next->next->next->next = new ListNode(12);
  RearrangeList::reorder(head);
  while (head != nullptr) {
    cout << head->value << " ";
    head = head->next;
  }
}
/*
Time Complexity is O(n)
Space Complexity is O(1)
*/