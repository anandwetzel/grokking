/*
Given the head of a LinkedList and a number ‘k’, reverse every ‘k’ 
sized sub-list starting from the head. If, in the end, you are left 
with a sub-list with less than ‘k’ elements, reverse it too.

Example:
    k = 3
    original list = head -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> null
    reversed sublist = head -> 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 8 -> 7 -> null
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

class ReverseEveryKElements {
  public:
    static ListNode *reverse(ListNode *head, int k) {
        if(k < 1 || head == nullptr) return head;
        ListNode *current = head;
        ListNode *prev = nullptr;
        while(true){
            ListNode *lastPrevNode = prev;
            ListNode *lastOfSub = current;
            ListNode *next = nullptr;
            for(int i = 0; current != nullptr && i < k; i++){
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            
            if(lastPrevNode != nullptr) lastPrevNode->next = prev;
            else head = prev;

            lastOfSub->next = current;
            if(current == nullptr) break;
            prev = lastOfSub;
        }
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
  head->next->next->next->next->next->next = new ListNode(7);
  head->next->next->next->next->next->next->next = new ListNode(8);

  ListNode *result = ReverseEveryKElements::reverse(head, 3);
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