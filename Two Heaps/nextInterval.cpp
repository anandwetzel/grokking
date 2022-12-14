/*
Given an array of intervals, find the next interval of each 
interval. In a list of intervals, for an interval ‘i’ its 
next interval ‘j’ will have the smallest ‘start’ greater 
than or equal to the ‘end’ of ‘i’.
Write a function to return an array containing indices 
of the next interval of each input interval. If there is 
no next interval of a given interval, return -1. It is given 
that none of the intervals have the same start point.

Example 1:
    Input: Intervals [[2,3], [3,4], [5,6]]      Output: [1, 2, -1]
    Explanation: The next interval of [2,3] is [3,4] having index ‘1’. 
    Similarly, the next interval of [3,4] is [5,6] having index ‘2’. 
    There is no next interval for [5,6] hence we have ‘-1’.
Example 2:
    Input: Intervals [[3,4], [1,5], [4,6]]      Output: [2, -1, -1]
    Explanation: The next interval of [3,4] is [4,6] which has index ‘2’. 
    There is no next interval for [1,5] and [4,6].
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class NextInterval {
 public:
  struct startCompare{
    bool operator()(const pair<Interval, int> &x, const pair<Interval, int> &y){
        return x.first.start < y.first.start;
    }
  };

  struct endCompare{
    bool operator()(const pair<Interval, int> &x, const pair<Interval, int> &y){
        return x.first.end < y.first.end;
    }
  };

  static vector<int> findNextInterval(const vector<Interval> &intervals) {
    int n = intervals.size();
    vector<int> result(n);
    priority_queue<pair<Interval, int>, vector<pair<Interval,int>>, startCompare> maxStartHeap;
    priority_queue<pair<Interval, int>, vector<pair<Interval, int>>, endCompare> maxEndHeap;
    for(int i = 0; i < n; i++){
        maxStartHeap.push(make_pair(intervals[i], i));
        maxEndHeap.push(make_pair(intervals[i], i));
    }
    for(int i = 0; i < n; i++){
        auto topEnd = maxEndHeap.top();
        maxEndHeap.pop();
        result[topEnd.second] = -1;
        if(maxStartHeap.top().first.start >= topEnd.first.end){
            auto topStart = maxStartHeap.top();
            maxStartHeap.pop();
            while(!maxStartHeap.empty() && maxStartHeap.top().first.start >= topEnd.first.end){
                topStart = maxStartHeap.top();
                maxStartHeap.pop();
            }
            result[topEnd.second] = topStart.second;
            maxStartHeap.push(topStart);
        }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> intervals = {{2, 3}, {3, 4}, {5, 6}};
  vector<int> result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
  cout << endl;

  intervals = {{3, 4}, {1, 5}, {4, 6}};
  result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
}

/*
Time Complexity is O(nlogn)
Space Complexity is O(n)
*/