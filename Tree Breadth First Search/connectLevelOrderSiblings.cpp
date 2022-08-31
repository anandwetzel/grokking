/*
Given a binary tree, connect each node with its 
level order successor. The last node of each 
level should point to a null node.

Example 1:
            1 -> null
          2 -> 3 -> null
    4 -> 5 -> 6 -> 7 -> null
Example 2:
      12 -> null
    7 -> 1 -> null
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

  // level order traversal using 'next' pointer
  virtual void printLevelOrder() {
    TreeNode *nextLevelRoot = this;
    while (nextLevelRoot != nullptr) {
      TreeNode *current = nextLevelRoot;
      nextLevelRoot = nullptr;
      while (current != nullptr) {
        cout << current->val << " ";
        if (nextLevelRoot == nullptr) {
          if (current->left != nullptr) {
            nextLevelRoot = current->left;
          } else if (current->right != nullptr) {
            nextLevelRoot = current->right;
          }
        }
        current = current->next;
      }
      cout << endl;
    }
  }
};

class ConnectLevelOrderSiblings {
 public:
  static void connect(TreeNode *root) {
    queue<TreeNode *> queue;
    queue.push(root);
    while(!queue.empty()){
        int levelSize = queue.size();
        for(int i = 0; i < levelSize; i++){
            TreeNode *current = queue.front();
            queue.pop();
            if(i == levelSize - 1) current->next = nullptr;
            else current->next = queue.front();
            if(current->left != nullptr) queue.push(current->left);
            if(current->right != nullptr) queue.push(current->right);
        }
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
  ConnectLevelOrderSiblings::connect(root);
  cout << "Level order traversal using 'next' pointer: " << endl;
  root->printLevelOrder();
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/