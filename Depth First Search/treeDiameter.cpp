/*
Given a binary tree, find the length of its diameter. 
The diameter of a tree is the number of nodes on the 
longest path between any two leaf nodes. The diameter 
of a tree may or may not pass through the root.

Note: You can always assume that there are at least 
two leaf nodes in the given tree.

Example 1:
     1          Output: 5
    2 3         Explanation: The diameter of the tree is: [4, 2, 1, 3, 6]
    4 5 6
Example 2:
     1          Output: 7
    2 3         Explanation: The diameter of the tree is: [10, 8, 5, 3, 6, 9, 11]
     5 6
   7 8 9
    10 11
*/

#include <iostream>
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

class TreeDiameter {
 public:
    static int findDiameter(TreeNode *root) {
        int treeDiameter = 0;
        heightRecursive(root, treeDiameter);
        return treeDiameter;
    }
 private:
    static int heightRecursive(TreeNode *root, int &diameter){
        if(root == nullptr) return 0;
        int leftHeight = heightRecursive(root->left, diameter);
        int rightHeight = heightRecursive(root->right, diameter);
        if(leftHeight != 0 && rightHeight != 0){
            int tempDiameter = leftHeight + rightHeight + 1;
            diameter = max(diameter, tempDiameter);
        }
        return max(leftHeight, rightHeight) + 1;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
}
/*
Time Complexity is O(n)
Space Complexity is O(n)
*/