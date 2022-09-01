/*
Given a binary tree and a number sequence, 
find if the sequence is present as a 
root-to-leaf path in the given tree.

Example 1:
     1      Sequence: [1, 9, 9] 
    7 9     Output: true
     2 9    Explanation: The tree has a path 1 -> 9 -> 9.
Example 2:
     1      Sequence: [1, 0, 7] , [1, 1, 6]
    0 1     Output: false , true
    1 6 5  Explanation: Path includes 1 -> 0 -> 7 but not 1 -> 1 -> 6.
*/

#include <iostream>
#include <vector>

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

class PathWithGivenSequence {
 public:
    static bool findPath(TreeNode *root, const vector<int> &sequence) {
        if(root == nullptr) return sequence.empty();
        return findPathRecursive(root, sequence, 0);
    }

 private:
    static bool findPathRecursive(TreeNode *root, const vector<int> &sequence, int level){
        if(root == nullptr) return false;
        if(level >= sequence.size() || root->val != sequence[level]){
            return false;
        }
        if(root->left == nullptr && root->right == nullptr && 
            level == sequence.size() - 1){
            return true;
        }
        return findPathRecursive(root->left, sequence, level + 1) || 
                findPathRecursive(root->right, sequence, level + 1);
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(1);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(5);

  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 0, 7})
       << endl;
  cout << "Tree has path sequence: " << PathWithGivenSequence::findPath(root, vector<int>{1, 1, 6})
       << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/