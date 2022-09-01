/*
Given a binary tree and a number ‘S’, find all 
paths in the tree such that the sum of all the 
node values of each path equals ‘S’. Please note 
that the paths can start or end at any node but 
all paths must follow direction from parent to 
child (top to bottom).

Example 1:
     1      S: 12
    7 9     Output: 3
  6 5 2 3   Explanation: Three paths with sum 12: 7 -> 5, 1 -> 9 -> 2, and 9 -> 3
Example 2:
     12     S: 11
    7 1     Output: 2
    4 10 5  Explanation: Two paths with sum 11: 7 -> 4 . and 1 -> 10.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

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

class CountAllPathSum {
 public:
    static int countPaths(TreeNode *root, int S) {
        unordered_map<int, int> map;
        return countPathRecursive(root, S, 0, map);
    }
 private:
    static int countPathRecursive(TreeNode *root, int S, int currentSum, unordered_map<int, int> &map){
        if(root == nullptr) return 0;
        int paths = 0;
        currentSum += root->val;
        if(S == currentSum) paths++;
        if(map.find(currentSum - S) != map.end()){
            paths += map[currentSum - S];
        }
        map[currentSum]++;
        paths += countPathRecursive(root->left, S, currentSum, map);
        paths += countPathRecursive(root->right, S, currentSum, map);
        map[currentSum]--;
        return paths;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(n)
*************************
*A LESS OPTIMAL SOLUTION*
*************************
class CountAllPathSum {
 public:
    static int countPaths(TreeNode *root, int S) {
        vector<int> currentPath;
        if(root == nullptr) return 0;
        return countPathRecursive(root, S, currentPath);
    }
 private:
    static int countPathRecursive(TreeNode *root, int S, vector<int> &currentPath){
        if(root == nullptr) return 0;
        int paths = 0, sum = 0;
        currentPath.push_back(root->val);
        for(vector<int>::reverse_iterator itr = currentPath.rbegin(); 
                itr != currentPath.rend(); itr++){
            sum += *itr;
            if(sum == S) paths++;
        }
        paths += countPathRecursive(root->left, S, currentPath);
        paths += countPathRecursive(root->right, S, currentPath);
        currentPath.pop_back();
        return paths;
    }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(12);
  root->left = new TreeNode(7);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(10);
  root->right->right = new TreeNode(5);
  cout << "Tree has path: " << CountAllPathSum::countPaths(root, 11) << endl;
}

Time Complexity is O(nlogn)
Space Complexity is O(n)
*/