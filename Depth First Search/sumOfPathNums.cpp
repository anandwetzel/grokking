/*
Given a binary tree where each node can only have 
a digit (0-9) value, each root-to-leaf path will 
represent a number. Find the total sum of all the 
numbers represented by all paths.

Example 1:
     1      Output: 408
    7 9     Explanation: The sum of all path numbers: 17 + 192 + 199
     2 9
Example 2:
     1      Output: 332
    0 1     Explanation: The sum of all path numbers: 101 + 116 + 115
    1 6 5  
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

class SumOfPathNumbers {
 public:
    static int findSumOfPathNumbers(TreeNode *root) {
        return findSumOfPathRecursive(root, 0);
    }
 private:
    static int findSumOfPathRecursive(TreeNode *root, int sum){
        if(root == nullptr) return 0;
        sum = 10 * sum + root->val;
        if(root->left == nullptr && root->right == nullptr){
            return sum;
        }
        return findSumOfPathRecursive(root->left, sum) + findSumOfPathRecursive(root->right, sum);
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);
  cout << "Total Sum of Path Numbers: " << SumOfPathNumbers::findSumOfPathNumbers(root) << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/