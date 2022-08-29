/*
Given a string, find the length of the longest substring, which has all distinct characters.

Example 1:
    Input: String="aabccbb"         Output: 3
    Explanation: The longest substring with distinct characters is "abc".

Example 2:
    Input: String="abbbb"           Output: 2
    Explanation: The longest substring with distinct characters is "ab".

Example 3:
    Input: String="abccde"          Output: 3
    Explanation: Longest substrings with distinct characters are "abc" & "cde".
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class NoRepeatSubstring {
 public:
    static int findLength(const string& str) {
        int maxLength = 0;
        int windowStart = 0;
        unordered_map<char, int> uniqueChars;

        for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
            uniqueChars[str[windowEnd]]++;
            while(uniqueChars[str[windowEnd]] > 1){
                uniqueChars[str[windowStart]]--;
                windowStart++;
            }
            maxLength = max(maxLength, windowEnd - windowStart + 1);
        }
        return maxLength;
    }
};

int main() {
    cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
    cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
    cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(1)
*/