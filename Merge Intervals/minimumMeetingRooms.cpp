/*
Given a list of intervals representing the start and end 
time of ‘N’ meetings, find the minimum number of rooms 
required to hold all the meetings.

Example 1:
    Meetings: [[1,4], [2,5], [7,9]]         Output: 2
    Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these two meetings. [7,9] can 
    occur in any of the two rooms later.
Example 2:
    Meetings: [[6,7], [2,4], [8,12]]        Output: 1
    Explanation: None of the meetings overlap, therefore we only need one room to hold all meetings.
Example 3:
    Meetings: [[1,4], [2,3], [3,6]]         Output: 2
    Explanation: Since [1,4] overlaps with the other two meetings [2,3] and [3,6], we need two rooms to 
    hold all the meetings.
Example 4:
    Meetings: [[4,5], [2,3], [2,4], [3,5]]  Output: 2
    Explanation: We will need one room for [2,3] and [3,5], and another room for [2,4] and [4,5].
*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  struct endCompare {
    bool operator()(const Meeting &x, const Meeting &y) { return x.end > y.end; }
  };

  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    if(meetings.empty()) return 0;
    sort(meetings.begin(), meetings.end(),
      [](const Meeting &x, const Meeting &y) {return x.start < y.start; });
    priority_queue<Meeting, vector<Meeting>, endCompare> minHeap;
    int minRooms = 0;
    for(auto meeting : meetings){
      while(!minHeap.empty() && meeting.start >= minHeap.top().end){
        minHeap.pop();
      }
      minHeap.push(meeting);
      minRooms = max(minRooms, (int)minHeap.size());
    }
    return minRooms;
  }
};

int main(int argc, char *argv[]) {
  vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}
/*
Time Complexity is O(nlogn)
Space Complexity is O(n)
*/
