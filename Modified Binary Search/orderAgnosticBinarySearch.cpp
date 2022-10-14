/*
Given a sorted array of numbers, find if a given number ‘key’ 
is present in the array. Though we know that the array is sorted, 
we don’t know if it’s sorted in ascending or descending order. 
You should assume that the array can have duplicates.

Write a function to return the index of the ‘key’ if 
it is present in the array, otherwise return -1.

Example 1:
    Input: [4, 6, 10], key = 10             Output: 2

Example 2:
    Input: [1, 2, 3, 4, 5, 6, 7], key = 5   Output: 4

Example 3:
    Input: [10, 6, 4], key = 10             Output: 0

Example 4:
    Input: [10, 6, 4], key = 4              Output: 2
*/

#include <iostream>
#include <vector>

using namespace std;

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    return -1; 
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}

/*
Time Complexity is O()
Space Complexity is O()
*/