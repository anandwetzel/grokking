/*
Given the head of a Singly LinkedList, write a method to 
check if the LinkedList is a palindrome or not.
Your algorithm should use constant space and the input 
LinkedList should be in the original form once the 
algorithm is finished. The algorithm should have O(N)
O(N) time complexity where ‘N’ is the number of nodes 
in the LinkedList.
Example 1:
    Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
    Output: true
Example 2:
    Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
    Output: false
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

class PalindromicLinkedList {
 public:
  static bool isPalindrome(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return true;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *headSecondHalf = reverse(slow); 
    ListNode *copyHeadSecondHalf =
        headSecondHalf;

    while (head != nullptr && headSecondHalf != nullptr) {
      if (head->value != headSecondHalf->value) {
        break;
      }
      head = head->next;
      headSecondHalf = headSecondHalf->next;
    }

    reverse(copyHeadSecondHalf); 
    if (head == nullptr || headSecondHalf == nullptr) { 
      return true;
    }
    return false;
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
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;

  head->next->next->next->next->next = new ListNode(2);
  cout << "Is palindrome: " << PalindromicLinkedList::isPalindrome(head) << endl;
}
/*
Time Complexity is O(n)
Space Complexity is O(1)
*/