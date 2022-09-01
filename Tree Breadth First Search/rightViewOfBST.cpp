/*
Given a binary tree, return an array containing 
nodes in its right view. The right view of a 
binary tree is the set of nodes visible when 
the tree is seen from the right side.

Example 1:
        1       Right View: [1, 3, 7]
       2 3
     4 5 6 7
Example 2:
    12          Right View: [12, 1, 5, 3]
    7 1
    9 10 5
    3
*/

#include <iostream>
#include <queue>
#include <vector>

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

class RightViewTree {
 public:
  static vector<TreeNode *> traverse(TreeNode *root) {
    vector<TreeNode *> result;
    queue<TreeNode *> queue;
    queue.push(root);
    while(!queue.empty()){
        int levelSize = queue.size();
        for(int i = 0; i < levelSize; ++i){
            TreeNode *current = queue.front();
            queue.pop();
            if(i == levelSize - 1) result.push_back(current);
            if(current->left != nullptr) queue.push(current->left);
            if(current->right != nullptr) queue.push(current->right);
        }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  root->left->left->left = new TreeNode(3);
  vector<TreeNode *> result = RightViewTree::traverse(root);
  for (auto node : result) {
    cout << node->val << " ";
  }
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/