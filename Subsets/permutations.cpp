/*
Given a set of distinct numbers, find all of its permutations.
Permutation is defined as the re-arranging of the elements of 
the set. For example, {1, 2, 3} has six permutations.
If a set has ‘n’ distinct elements it will have n! permutations.

Example 1:
    Input: [1,3,5]
    Output: [1,3,5], [1,5,3], [3,1,5], [3,5,1], [5,1,3], [5,3,1]
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Permutations {
 public:
  static vector<vector<int>> findPermutations(const vector<int>& nums) {
    vector<vector<int>> result;
    queue<vector<int>> permutations;
    permutations.push(vector<int>());
    for(auto current : nums){
        int n = permutations.size();
        for(int i = 0; i < n; i++){
            vector<int> oldPermutation = permutations.front();
            permutations.pop();
            for(int j = 0; j <= oldPermutation.size(); j++){
                vector<int> newPermutation = oldPermutation;
                newPermutation.insert(newPermutation.begin() + j, current);
                if(newPermutation.size() == nums.size()){
                    result.push_back(newPermutation);
                }else{
                    permutations.push(newPermutation);
                }
            }//j
        }//i
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Permutations::findPermutations(vector<int>{1, 3, 5});
  cout << "Here are all the permutations: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

/*
Time Complexity is O(n*n!)
Space Complexity is O(n*n!)
*/