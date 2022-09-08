/*
Given a set with distinct elements, find all of its distinct subsets.

Example 1:
    Input: [1, 3]
    Output: [], [1], [3], [1,3]
Example 2:
    Input: [1, 5, 3]
    Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]
*/

#include <iostream>
#include <vector>

using namespace std;

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    subsets.push_back(vector<int>());
    for(auto current : nums){
        int n = subsets.size();
        for(int i = 0; i < n; i++){
            vector<int> set(subsets[i]);
            set.push_back(current);
            subsets.push_back(set);
        }//i
    }//current
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

/*
Time Complexity is O(n*2^n)
Space Complexity is O(n*2^n)
*/