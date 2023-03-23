#include "LinkedList.cpp"	

EduLinkedListNode* GetMiddleNode(EduLinkedListNode* head){
  EduLinkedListNode *slow = head, *fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// Time Complexity O(n)
// Space Complexity O(1)