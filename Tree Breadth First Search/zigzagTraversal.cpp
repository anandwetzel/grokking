/*
Given a binary tree, populate an array to represent its 
zigzag level order traversal. You should populate the 
values of all nodes of the first level from left to right, 
then right to left for the next level and keep alternating 
in the same manner for the following levels.

Example 1:
    Zigzag Level Traversal Order: [[1],[3, 2],[4, 5, 6, 7]]
Example 2:
    Zigzag Level Traversal Order: [[12],[1,7],[9,10,5][17,20]]
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

class ZigzagTraversal {
 public:
  static vector<vector<int>> traverse(TreeNode *root) {
    vector<vector<int>> result;
    if(root == nullptr) return result;
    queue<TreeNode *> queue;
    queue.push(root);
    bool leftOrRight = true;
    while(!queue.empty()){
        int levelSize = queue.size();
        vector<int> currentLevel(levelSize);
        for(int i = 0; i < levelSize; ++i){
            TreeNode *current = queue.front();
            queue.pop();
            if(leftOrRight) currentLevel[i] = current->val;
            else currentLevel[levelSize - 1 - i] = current->val;
            if(current->left != nullptr) queue.push(current->left);
            if(current->right != nullptr) queue.push(current->right);
        }
        result.push_back(currentLevel);
        leftOrRight = !leftOrRight;
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
  root->right->left->left = new TreeNode(20);
  root->right->left->right = new TreeNode(17);
  vector<vector<int>> result = ZigzagTraversal::traverse(root);
  cout << "Zigzag traversal: ";
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
  }
}


/*
Time Complexity is O(n)
Space Complexity is O(n)
*/