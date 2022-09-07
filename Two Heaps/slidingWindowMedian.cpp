/*
Problem Statement
Given an array of numbers and a number ‘k’, find the median 
of all the ‘k’ sized sub-arrays (or windows) of the array.

Example 1:
    Input: nums=[1, 2, -1, 3, 5], k = 2     Output: [1.5, 0.5, 1.0, 4.0]
    Explanation: Lets consider all windows of size ‘2’:
    [1, 2] -> median is 1.5
    [2, -1] -> median is 0.5
    [-1, 3] -> median is 1.0
    [3, 5] -> median is 4.0
Example 2:
    Input: nums=[1, 2, -1, 3, 5], k = 3     Output: [1.0, 2.0, 3.0]
    Explanation: Lets consider all windows of size ‘3’:
    [1, 2, -1, 3, 5] -> median is 1.0
    [1, 2, -1, 3, 5] -> median is 2.0
    [1, 2, -1, 3, 5] -> median is 3.0
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T, class Container = vector<T>,
          class Compare = less<typename Container::value_type>>
class priority_queue_with_remove : public priority_queue<T, Container, Compare> {
 public:
  bool remove(const T &valueToRemove) {
    auto itr = std::find(this->c.begin(), this->c.end(), valueToRemove);
    if (itr == this->c.end()) {
      return false;
    }
    this->c.erase(itr);
    std::make_heap(this->c.begin(), this->c.end(), this->comp);
    return true;
  }
};

class SlidingWindowMedian {
 public:
    priority_queue_with_remove<int> maxHeap;
    priority_queue_with_remove<int, vector<int>, greater<int>> minHeap;
    virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
        vector<double> result(nums.size() - k + 1);

        for(int i = 0; i < nums.size(); i++){
            if(maxHeap.size() == 0 || maxHeap.top() >= nums[i]){
                maxHeap.push(nums[i]);
            }else minHeap.push(nums[i]);
            rebalanceHeap();
            if(i - k + 1 >= 0){
                if(maxHeap.size() == minHeap.size()){
                    result[i - k + 1] = maxHeap.top() / 2.0 + minHeap.top() / 2.0;
                }else result[i - k + 1] = maxHeap.top();
                int elRemove = nums[i - k + 1];
                if(elRemove <= maxHeap.top()){
                    maxHeap.remove(elRemove);
                }else minHeap.remove(elRemove);
                rebalanceHeap();
            }
        }
        return result;
    }
 private: 
    void rebalanceHeap(){
        if(maxHeap.size() < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }else if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result =
      slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}

/*
Time Complexity is O(n + k) n = # elements, k = window size
Space Complexity is O(k)
*/