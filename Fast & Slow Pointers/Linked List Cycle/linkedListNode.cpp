#include <iostream>

struct EduLinkedListNode {
	int data;
	EduLinkedListNode * next;
	EduLinkedListNode * arbitrary_pointer;
	EduLinkedListNode(int d) {
		data = d;
		next = nullptr;
		arbitrary_pointer = nullptr;
	}
};

// Template for traversing a linked list

void TraverseLinkedList(EduLinkedListNode* head){
    EduLinkedListNode* current = head; 
    EduLinkedListNode* nxt = nullptr; 
    while (current != nullptr){
      std::cout << current->data << "-> ";
      nxt = current->next;
      current = nxt;
    }
}

// Template for reversing a linked list

EduLinkedListNode* ReverseLinkedList(EduLinkedListNode* head){
	EduLinkedListNode* current = head; 
	EduLinkedListNode* prev = nullptr; 
    EduLinkedListNode* nxt = nullptr; 
	while (current != nullptr){
      nxt = current->next;
	  current->next = prev;
	  prev = current;
	  current = nxt;
	}
	return prev;
}