/*
Given an unsorted array containing numbers 
and a number ‘k’, find the first ‘k’ missing 
positive numbers in the array.

Example 1:
  Input: [3, -1, 4, 5, 5], k=3      Output: [1, 2, 6]
  Explanation: The smallest missing positive numbers are 1, 2 and 6.
Example 2:
  Input: [3, -1, 4, 5, 5], k=3      Output: [1, 2, 6]
  Explanation: The smallest missing positive numbers are 1, 2 and 6.
Example 3:
  Input: [3, -1, 4, 5, 5], k=3      Output: [1, 2, 6]
  Explanation: The smallest missing positive numbers are 1, 2 and 6.
*/

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    vector<int> missingNumbers;
    int i = 0;
    while(i < nums.size()){
      if(nums[i] > 0 && nums[nums[i] - 1] != nums[i] && nums[i] <= nums.size()){
        swap(nums, i, nums[i] - 1);
      }else i++;
    }
    
    unordered_set<int> extraNums;
    for(i = 0; i < nums.size() && missingNumbers.size() < k; i++){
      if(nums[i] != i + 1){
        missingNumbers.push_back(i + 1);
        extraNums.insert(nums[i]);
      }
    }

    for(i = 1; missingNumbers.size() < k; i++){
      int num = nums.size() + i;
      if(extraNums.find(num) == extraNums.end()){
        missingNumbers.push_back(num);
      }
    }

    return missingNumbers;
  }
 private:
  static void swap(vector<int> &nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, -1, 4, 5, 5};
  vector<int> missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {-2, -3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 2);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(1)
*/