/*
Given a string, find all of its permutations preserving 
the character sequence but changing case.

Example 1:
    Input: "ad52"
    Output: "ad52", "Ad52", "aD52", "AD52" 
Example 2:
    Input: "ab7c"
    Output: "ab7c", "Ab7c", "aB7c", "AB7c", "ab7C", "Ab7C", "aB7C", "AB7C"
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LetterCaseStringPermutation {
 public:
  static vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    if(str == "") return permutations;
    permutations.push_back(str);
    for(int i = 0; i < str.length(); i++){
        if(isalpha(str[i])){ // if its a char
            int n = permutations.size();
            for(int j = 0; j < n; j++){ // push back each version after changing case
                vector<char> strs(permutations[j].begin(), permutations[j].end());
                if(isupper(strs[i])){
                    strs[j] = tolower(strs[j]);
                }else strs[j] = toupper(strs[j]);
                permutations.push_back(string(strs.begin(), strs.end()));
            }//j
        }//i
    }
    return permutations;
  }
};

int main(int argc, char* argv[]) {
  vector<string> result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ad52");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ab7c");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}

/*
Time Complexity is O(n*2^n)
Space Complexity is O(n*2^n)
*/