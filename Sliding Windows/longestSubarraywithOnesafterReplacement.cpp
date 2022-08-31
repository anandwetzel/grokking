/*
Given an array containing 0s and 1s, if you are allowed to 
replace no more than ‘k’ 0s with 1s, find the length of 
the longest contiguous subarray having all 1s.

Example 1:
    Input: Array=[0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], k=2
    Output: 6
    Explanation: Replace the '0' at index 5 and 8 to have the 
        longest contiguous subarray of 1s having length 6.

Example 2:
    Input: Array=[0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1], k=3
    Output: 9
    Explanation: Replace the '0' at index 6, 9, and 10 to have 
        the longest contiguous subarray of 1s having length 9.

*/

#include <iostream>
#include <vector>

using namespace std;

class ReplacingOnes {
 public:
    static int findLength(const vector<int>& arr, int k) {
        int maxLength = 0;
        int windowStart = 0;
        int onesCount = 0;

        for(int windowEnd = 0; windowEnd < arr.size(); windowEnd++){
            if(arr[windowEnd] == 1) onesCount++;
            if(windowEnd - windowStart + 1 - onesCount <= k){
                maxLength = max(maxLength, windowEnd - windowStart + 1);
            }else{
                if(arr[windowStart] == 1) onesCount--;
                windowStart++;
            }
        }
        return maxLength;
    }
};

int main(int argc, char* argv[]) {
    vector<int> example1 = {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1};
    vector<int> example2 = {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1};
    cout << "length = " << ReplacingOnes::findLength(example1, 2) << endl;
    cout << "length = " << ReplacingOnes::findLength(example2, 3) << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(1)
*/