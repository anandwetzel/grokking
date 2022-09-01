/*
Given a binary tree, connect each node with its level 
order successor. The last node of each level should 
point to the first node of the next level.

Example 1 (arrows at end wrap around):
    1 -> 
    2 -> 3 ->
    4 -> 5 -> 6 -> 7 -> null
Example 2:
    12 ->
    7 -> 1 ->
    9 -> 10 -> 5 -> null
*/

#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;
  TreeNode *next;

  TreeNode(int x) {
    val = x;
    left = right = next = nullptr;
  }

  // tree traversal using 'next' pointer
  virtual void printTree() {
    TreeNode *current = this;
    cout << "Traversal using 'next' pointer: ";
    while (current != nullptr) {
      cout << current->val << " ";
      current = current->next;
    }
  }
};

class ConnectAllSiblings {
 public:
  static void connect(TreeNode *root) {
    if(root == nullptr) return;
    queue<TreeNode *> queue;
    queue.push(root);
    while(!queue.empty()){
        TreeNode *current = queue.front();
        queue.pop();
        if(current->left != nullptr) queue.push(current->left);
        if(current->right != nullptr) queue.push(current->right);
        if(!queue.empty()) current->next = queue.front();
        else current->next = nullptr;
    }
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  ConnectAllSiblings::connect(root);
  root->printTree();
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/