/*
Given a binary tree, populate an array to represent 
its level-by-level traversal. You should populate 
the values of all nodes of each level from left to
right in separate sub-arrays.

Example 1:
    Level Order Traversal: [[1],[2,3],[4,5,6,7]]
Example 2:
    Level Order Traversal: [[12],[7,1],[9,10,5]]
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

class LevelOrderTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if(root == nullptr) return result;
    queue<TreeNode *> numQueue;
    numQueue.push(root);
    while(!numQueue.empty()){
        vector<int> currentLevel;
        int levelSize = numQueue.size();
        for(int i = 0; i < levelSize; ++i){
            TreeNode *current = numQueue.front();
            numQueue.pop();
            currentLevel.push_back(current->val);
            if(current->left != nullptr) numQueue.push(current->left);
            if(current->right != nullptr) numQueue.push(current->right);
        }
        result.push_back(currentLevel);
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
  vector<vector<int>> result = LevelOrderTraversal::traverse(root);
  cout << "Level order traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/