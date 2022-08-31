/*
Given an unsorted array containing numbers, 
find the smallest missing positive number in it.
Note: Positive numbers start from ‘1’.

Example 1:
  Input: [-3, 1, 5, 4, 2]     Output: 3
Example 2:
  Input: [3, -2, 0, 1, 2]     Output: 4
Example 3:
  Input: [3, 2, 5, 1]         Output: 4
*/

#include <iostream>
#include <vector>

using namespace std;

class FirstSmallestMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    int i = 0;
    while(i < nums.size()){
      if(nums[i] > 0 && nums[i] != nums[nums[i] - 1] && nums[i] < nums.size()){
        swap(nums, i, nums[i] - 1);
      }else i++;
    }
    for(int i = 0; i < nums.size(); i++){
      if(nums[i] != i + 1){
        return i + 1;
      }
    }
    return nums.size() + 1;
  }
 private:
  static void swap(vector<int> &nums, int i, int j){
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {-3, 1, 5, 4, 2};
  cout << "missing " << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, -2, 0, 1, 2};
  cout << "missing " << FirstSmallestMissingPositive::findNumber(v1) << endl;

  v1 = {3, 2, 5, 1};
  cout << "missing " << FirstSmallestMissingPositive::findNumber(v1) << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(1)
*/