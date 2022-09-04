/*
Given an array of unsorted numbers and a target number, 
find all unique quadruplets in it, whose sum is equal 
to the target number.

Example 1:
    Input: [4, 1, 2, -1, 1, -3], target=1
    Output: [-3, -1, 1, 4], [-3, 1, 1, 2]
    Explanation: Both the quadruplets add up to the target.
Example 2:
    Input: [2, 0, -1, 1, -2, 2], target=2
    Output: [-2, 0, 2, 2], [-1, 0, 1, 2]
    Explanation: Both the quadruplets add up to the target.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class QuadrupleSumToTarget {
 public:
  static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    vector<vector<int>> quadruplets;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size() - 3; i++){
      if(i > 0 && arr[i] == arr[i-1]) continue;
      for(int j = i + 1; j < arr.size() - 2; j++){
        if(j > i + 1 && arr[j] == arr[j-1]) continue;
        int left = j + 1, right = arr.size() - 1;
        while(left < right){
          int sum = arr[i] + arr[j] + arr[left] + arr[right];
          if(sum == target){
            quadruplets.push_back({arr[i], arr[j], arr[left], arr[right]});
            left++;
            right--;
          }else if(sum < target) left++;
          else right--;
        }
        
      }
    }
    return quadruplets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {4, 1, 2, -1, 1, -3};
  auto result = QuadrupleSumToTarget::searchQuadruplets(vec, 1);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {2, 0, -1, 1, -2, 2};
  result = QuadrupleSumToTarget::searchQuadruplets(vec, 2);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
/*
Time Complexity is O(n^3)
Space Complexity is O(n)
*/