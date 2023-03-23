#include "linkedList.cpp"

bool DetectCycle(EduLinkedListNode* head){
  EduLinkedListNode *slow = head;
  EduLinkedListNode *fast = head;
  while(fast && fast->next){
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) return true;
  }
  return false;
}

int main(){
  // test case
}

// Time Complexity O(n)
// Space Complexity O(1)