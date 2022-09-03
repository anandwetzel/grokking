/*
For ‘K’ employees, we are given a list of intervals 
representing the working hours of each employee. 
Our goal is to find out if there is a free interval 
that is common to all employees. You can assume that 
each list of employee working hours is sorted on the start time.

Example 1:
    Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]      Output: [3,5]
    Explanation: Both the employees are free between [3,5].
Example 2:
    Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]   Output: [4,6], [8,9]
    Explanation: All employees are free between [4,6] and [8,9].
Example 3:
    Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]    Output: [5,7]
    Explanation: All employees are free between [5,7].
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

class EmployeeFreeTime {
 public:
  struct startCompare{
    bool operator()(const pair<Interval, pair<int, int>> &x, 
                    const pair<Interval, pair<int, int>> &y) {
      return x.first.start > y.first.start;
    }
  };

  static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
    vector<Interval> result;
    if(schedule.empty()) return result;
    priority_queue<pair<Interval, pair<int, int>>, vector<pair<Interval, pair<int, int>>>,
                   startCompare> minHeap;
    for(int i = 0; i < schedule.size(); i++){
      minHeap.push(make_pair(schedule[i][0], make_pair(i, 0)));
    }
    Interval previousInt = minHeap.top().first;
    while(!minHeap.empty()){
      auto queueTop = minHeap.top();
      minHeap.pop();
      if(previousInt.end < queueTop.first.start){
        result.push_back({previousInt.end, queueTop.first.start});
        previousInt = queueTop.first;
      }else{
        if(previousInt.end < queueTop.first.end) previousInt = queueTop.first;
      }

      vector<Interval> eSchedule = schedule[queueTop.second.first];
      if(eSchedule.size() > queueTop.second.second + 1){
        minHeap.push(make_pair(eSchedule[queueTop.second.second + 1],
          make_pair(queueTop.second.first, queueTop.second.second + 1)));
      }
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<Interval>> input = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
}
/*
Time Complexity is O(nlogn)
Space Complexity is O(n)
*/