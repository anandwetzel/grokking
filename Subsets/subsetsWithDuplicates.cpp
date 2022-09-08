/*
Given a set of numbers that might contain duplicates, 
find all of its distinct subsets.

Example 1:
    Input: [1, 3, 3]
    Output: [], [1], [3], [1,3], [3,3], [1,3,3]
Example 2:
    Input: [1, 5, 3, 3]
    Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], 
    [3,3], [1,3,3], [3,3,5], [1,5,3,3] 
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    sort(nums.begin(), nums.end()); // sort, add {}
    subsets.push_back(vector<int>());
    int startIndex = 0, endIndex = 0;
    for(int i = 0; i < nums.size(); i++){ // go through input
        startIndex = 0;
        if(i > 0  && nums[i] == nums[i-1]){ // avoid duplicates
            startIndex = endIndex + 1;
        }
        endIndex = subsets.size() - 1;
        for(int j = startIndex; j <= endIndex; ++j){ // add new num to sets
            vector<int> set(subsets[j]);
            set.push_back(nums[i]);
            subsets.push_back(set);
        }//j
    }//i
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

/*
Time Complexity is O(n*n^2)
Space Complexity is O(n*n^2)
*/