/*
Given a binary tree and a number ‘S’, find if the 
tree has a path from root-to-leaf such that the 
sum of all the node values of that path equals ‘S’.

Example 1:
       1            S: 10
      2 3           Output: true  
    4 5 6 7         Explanation: There is a path with the sum 10.
Example 2:
    12              S: 23, 16
    7 1             Output: true, false
    9 10 5          Explanation: There is a path with sum 23 but not 16
*/

#include <iostream>

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

class TreePathSum {
 public:
  static bool hasPath(TreeNode *root, int sum) {
    if(root == nullptr) return false;
    sum -= root->val;
    if(sum == 0 && root->left == nullptr && root->right == nullptr){
        return true;
    }
    return hasPath(root->left, sum) || hasPath(root->right, sum);
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << TreePathSum::hasPath(root, 23) << endl;
  cout << "Tree has path: " << TreePathSum::hasPath(root, 16) << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/