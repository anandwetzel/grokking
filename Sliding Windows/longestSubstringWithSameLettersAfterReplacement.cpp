/*
Given a string with lowercase letters only, if you are allowed to replace 
no more than k letters with any letter, find the length of the longest 
substring having the same letters after replacement.

Example 1:
Input: String="aabccbb", k=2            Output: 5
Explanation: Replace the two 'c' with 'b' to have the longest repeating substring "bbbbb".

Example 2:
Input: String="abbcb", k=1              Output: 4
Explanation: Replace the 'c' with 'b' to have the longest repeating substring "bbbb".

Example 3:
Input: String="abccde", k=1             Output: 3
Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating substring "ccc".
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class CharacterReplacement {
 public:
    static int findLength(const string& str, int k) {
        int maxLength = 0;
        int windowStart = 0;
        int mostRepeated = 0;
        unordered_map<char, int> diffCharCount;

        for(int windowEnd = 0; windowEnd < str.length(); windowEnd++){
            diffCharCount[str[windowEnd]]++;
            mostRepeated = max(mostRepeated, diffCharCount[str[windowEnd]]);
            if(windowEnd - windowStart + 1 - mostRepeated <= k){
                maxLength = max(maxLength, windowEnd - windowStart + 1);
            }else{
                diffCharCount[str[windowStart]]--;
                if(diffCharCount[str[windowStart]] == 0) diffCharCount.erase(str[windowStart]);
                windowStart++;
            }
        }

        return maxLength;
    }
};

int main(int argc, char *argv[]) {
  cout << "length: " << CharacterReplacement::findLength("aabccbb", 2) << endl;
  cout << "length: " << CharacterReplacement::findLength("abbcb", 1) << endl;
  cout << "length: " << CharacterReplacement::findLength("abccde", 1) << endl;
}
/*
Time Complexity is O(n)
Space Complexity is O(1)
*/