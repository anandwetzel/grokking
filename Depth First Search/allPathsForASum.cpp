/*
Given a binary tree and a number ‘S’, find 
all paths from root-to-leaf such that the sum 
of all the node values of each path equals ‘S’.

Example 1:
       1        S: 12
      7 9       Output: [[1, 7, 4], [1, 9, 2]]  
    4 5 2 7     
    Explanation: Two paths with sum = 12: 1 -> 7 -> 4 and 1 -> 9 -> 2
Example 2:
    12              S: 23
    7 1             Output: [[12, 7, 4], [12, 1, 10]]
    4 10 5 
    Explanation: Two paths with sum = 23: 12 -> 7 -> 4 and 12 -> 1 -> 10
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

class FindAllTreePaths {
 public:
    static vector<vector<int>> findPaths(TreeNode *root, int sum) {
        vector<vector<int>> allPaths;
        vector<int> somePath;
        findPath(root, sum, allPaths, somePath);
        return allPaths;
    }
 private:
    static void findPath(TreeNode *root, int sum, vector<vector<int>> &allPaths, vector<int> &somePath){
        if(root == nullptr) return;
        somePath.push_back(root->val);
        if(sum == root->val && root->left == nullptr && root->left == nullptr){
            allPaths.push_back(somePath);
        }else{
            findPath(root->left, sum - root->val, allPaths, somePath);
            findPath(root->right, sum - root->val, allPaths, somePath);
        }
        somePath.pop_back();
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  int sum = 23;
  vector<vector<int>> result = FindAllTreePaths::findPaths(root, sum);
  cout << "Tree paths with sum " << sum << ": " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

/*
Time Complexity is O(nlogn)
Space Complexity is O(nlogn)
*/