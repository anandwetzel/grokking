/*
Given an array, find the length of the smallest 
subarray in it which when sorted will sort the whole array.

Example 1:
    Input: [1, 2, 5, 3, 7, 10, 9, 12]       Output: 5
    Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted
Example 2:
    Input: [1, 3, 2, 0, -1, 7, 10]          Output: 5
    Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
Example 3:
    Input: [1, 2, 3]                        Output: 0
    Explanation: The array is already sorted
Example 4:
    Input: [3, 2, 1]                        Output: 3
    Explanation: The whole array needs to be sorted.
*/

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class ShortestWindowSort {
 public:
  static int sort(const vector<int>& arr) {
    int low = 0, high = arr.size() - 1;
    while(low < arr.size() - 1 && arr[low] <= arr[low + 1]) low++;
    if(low == arr.size() - 1) return 0;
    while(high > 0 && arr[high] >= arr[high - 1]) high--;
    int max = numeric_limits<int>::min(), min = numeric_limits<int>::max(); 
    for(int i = low; i <= high; i++){
      if(arr[i] > max) max = arr[i];
      if(arr[i] < min) min = arr[i];
    }

    while(low > 0 && arr[low - 1] > min) low--;
    while(high < arr.size() - 1 && arr[high + 1] < max) high++;

    return high - low + 1;
  }
};
int main(int argc, char* argv[]) {
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 3}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{3, 2, 1}) << endl;
}
/*
Time Complexity is O(n)
Space Complexity is O(1)
*/