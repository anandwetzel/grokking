/*
Find the minimum depth of a binary tree. The minimum
depth is the number of nodes along the shortest path 
from the root node to the nearest leaf node.

Example 1: Minimum Tree Depth = 2
Example 2: Minimum Tree Depth  = 3
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

class MinimumBinaryTreeDepth {
 public:
  static int findDepth(TreeNode *root) {
    int minimumTreeDepth = 0;
    if(root == nullptr) return minimumTreeDepth;
    queue<TreeNode *> queue;
    queue.push(root);
    while(!queue.empty()){
        minimumTreeDepth++;
        int levelSize = queue.size();
        for(int i = 0; i < levelSize; ++i){
            TreeNode *current = queue.front();
            queue.pop();
            if(current->left == nullptr && current->right == nullptr) return minimumTreeDepth;
            if(current->left != nullptr) queue.push(current->left);
            if(current->right != nullptr) queue.push(current->right);
        }
    }
    return minimumTreeDepth;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
  root->left->left = new TreeNode(9);
  root->right->left->left = new TreeNode(11);
  cout << "Tree Minimum Depth: " << MinimumBinaryTreeDepth::findDepth(root) << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/