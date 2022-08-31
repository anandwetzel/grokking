/*
We are given an unsorted array containing ‘n’ numbers taken
from the range 1 to ‘n’. The array originally contained all 
the numbers from 1 to ‘n’, but due to a data error, one of 
the numbers got duplicated which also resulted in one number 
going missing. Find both these numbers.

Example 1:
    Input: [3, 1, 2, 5, 2]          Output: [2, 4]
    Explanation: '2' is duplicated and '4' is missing.
Example 2:
    Input: [3, 1, 2, 3, 6, 4]           Output: [3, 5]
    Explanation: '3' is duplicated and '5' is missing.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    int i = 0;
    while(i < nums.size()){
      if(nums[i] != nums[nums[i] - 1]){
        swap(nums, i, nums[i] - 1);
      }else i++;
    }
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] != i + 1) return vector<int>{nums[i], i + 1};
    }
    return vector<int>{-1, -1};
  }
 private:
  static void swap(vector<int> &nums, int i, int j){
    int temp = nums[j];
    nums[j] = nums[i];
    nums[i] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 1, 2, 5, 2};
  vector<int> nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << " is duplicated, " << nums[1] << " is missing" << endl;

  v1 = {3, 1, 2, 3, 6, 4};
  nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << " is duplicated, " << nums[1] << " is missing" << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(1)
*/