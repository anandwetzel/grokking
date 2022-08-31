/*
Given a binary tree, populate an array to represent its
level-by-level traversal in reverse order, i.e., the lowest
level comes first. You should populate the values of all 
nodes in each level from left to right in separate sub-arrays.

Example 1:
    Reverse Level Order Traversal: [[4,5,6,7],[2,3],[1]] 
Example 2:
    Reverse Level Order Traversal: [[9,10,5],[7,1],[12]] 
*/

#include <iostream>
#include <queue>
#include <deque>

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

class ReverseLevelOrderTraversal {
 public:
  static deque<vector<int>> traverse(TreeNode *root) {
    deque<vector<int>> result = deque<vector<int>>();
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
        result.push_front(currentLevel);
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
  auto result = ReverseLevelOrderTraversal::traverse(root);

  cout << "Reverse level order traversal: ";
  for (auto que : result) {
    for (auto num : que) {
      cout << num << " ";
    }
    cout << endl;
  }
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/