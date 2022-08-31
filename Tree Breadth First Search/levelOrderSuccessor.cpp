/*
Given a binary tree and a node, find the level 
order successor of the given node in the tree. 
The level order successor is the node that appears 
right after the given node in the level order traversal.

Example 1:
    Given Node: 3       Level Order Successor: 4
Example 2: 
    Given Node: 9       Level Order Successor: 10
Example 3:
    Given Node: 12       Level Order Successor: 7
*/

#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class LevelOrderSuccessor {
 public:
  static TreeNode *findSuccessor(TreeNode *root, int key) {
    queue<TreeNode *> queue;
    if(root == nullptr) return root;
    queue.push(root);
    while(!queue.empty()){
        TreeNode *current = queue.front();
        queue.pop();
        if(current->left != nullptr) queue.push(current->left);
        if(current->right != nullptr) queue.push(current->right);
        if(current->val == key) break;
    }
    return queue.front();
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  
  TreeNode *result = LevelOrderSuccessor::findSuccessor(root, 3);
  if (result != nullptr) {
    cout << "successor = " << result->val << " " << endl;
  }
  
  root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  
  result = LevelOrderSuccessor::findSuccessor(root, 9);
  if (result != nullptr) {
    cout << "successor = " << result->val << " " << endl;
  }
  
  result = LevelOrderSuccessor::findSuccessor(root, 12);
  if (result != nullptr) {
    cout << "successor = " << result->val << " " << endl;
  }
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/