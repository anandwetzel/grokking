/*
Given a number ‘n’, write a function to return all structurally 
unique Binary Search Trees (BST) that can store values 1 to ‘n’?

Example 1:
    Input: 2
    Output: List containing root nodes of all structurally unique BSTs.
    Explanation: 1 -> 2      2 -> 1

Example 2:
    Input: 3
    Output: List containing root nodes of all structurally unique BSTs.
    Explanation: 1->2->3    1->3->2     3->2->1     3->1->2     1<-2->3
*/

#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) { val = x; }
};

class UniqueTrees {
 public:
    static vector<TreeNode *> findUniqueTrees(int n) {
        vector<TreeNode *> result;
        if(n <= 0) return vector<TreeNode *> ();
        return findTreesRecursive(1, n);
    }
 private:
    static vector<TreeNode *> findTreesRecursive(int start, int end){
        vector<TreeNode *> result;
        if(start > end){
            result.push_back(nullptr);
            return result;
        }
        for(int i = start; i <= end; ++i){
            vector<TreeNode *> left = findTreesRecursive(start, i-1);
            vector<TreeNode *> right = findTreesRecursive(i+1, end);
            for(auto l : left){
                for(auto r: right){
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

int main(int argc, char *argv[]) {
  vector<TreeNode *> result = UniqueTrees::findUniqueTrees(2);
  cout << "Total trees: " << result.size() << endl;

  result = UniqueTrees::findUniqueTrees(3);
  cout << "Total trees: " << result.size() << endl;
}

/*
Time Complexity is O(4^n / n^(1/2))
Space Complexity is O(4^n / n^(1/2))
*/