/*
Given a binary tree, populate an array to 
represent the averages of all of its levels.

Example 1:
    Level Averages: [1, 2.5, 5.5]
Example 2:
    Level Averages: [12.0, 4.0, 6.5]
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

class LevelAverage {
 public:
  static vector<double> findLevelAverages(TreeNode *root) {
    vector<double> result;
    queue<TreeNode *> queue;
    queue.push(root);
    while(!queue.empty()){
      double levelSize = queue.size();
      double currentSum = 0;
      for(int i = 0; i < levelSize; ++i){
        TreeNode *current = queue.front();
        queue.pop();
        currentSum += current->val;
        if(current->left != nullptr) queue.push(current->left);
        if(current->right != nullptr) queue.push(current->right);
      }
      result.push_back(currentSum / levelSize);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(9);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  vector<double> result = LevelAverage::findLevelAverages(root);
  cout << "Level averages are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*/