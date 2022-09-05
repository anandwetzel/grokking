/*
Find the path with the maximum sum in a given binary 
tree. Write a function that returns the maximum sum.
A path can be defined as a sequence of nodes between 
any two nodes and doesn’t necessarily pass through 
the root. The path must contain at least one node.

Example 1:
     1          Output: 16
    2 3         Explanation: The path with maximum sum is: [4, 2, 1, 3, 6] 
    4 5 6
Example 2:
     1          Output: 31
    2 3         Explanation: The path with maximum sum is: [8, 5, 3, 6, 9] 
  1 3 5 6
     7 8 9
*/
#include <iostream>
#include <limits>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class MaximumPathSum {
 public:
    static int findMaximumPathSum(TreeNode *root) {
        int sum = numeric_limits<int>::min();
        maxPathSumRecursive(root, sum);
        return sum;
    }
 private:
    static int maxPathSumRecursive(TreeNode *root, int &sum){
        if(root == nullptr) return 0;
        int leftSum = maxPathSumRecursive(root->left, sum);
        int rightSum = maxPathSumRecursive(root->right, sum);
        leftSum = max(leftSum, 0);
        rightSum = max(rightSum, 0);
        int tempSum = leftSum + rightSum + root->val;
        sum = max(sum, tempSum);
        return max(leftSum, rightSum) + root->val;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/