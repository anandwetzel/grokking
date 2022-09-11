/*
Given a word, write a function to generate 
all of its unique generalized abbreviations.
A generalized abbreviation of a word can be generated 
by replacing each substring of the word with the count 
of characters in the substring. Take the example of 
“ab” which has four substrings: “”, “a”, “b”, and “ab”. 
After replacing these substrings in the actual word by 
the count of characters, we get all the generalized 
abbreviations: “ab”, “1b”, “a1”, and “2”.
Note: All contiguous characters should be considered 
one substring, e.g., we can’t take “a” and “b” as 
substrings to get “11”; since “a” and “b” are contiguous,
we should consider them together as one substring to 
get an abbreviation “2”.

Example 1:
    Input: "BAT"
    Output: "BAT", "BA1", "B1T", "B2", "1AT", "1A1", "2T", "3"
Example 2:
    Input: "code"
    Output: "code", "cod1", "co1e", "co2", "c1de", "c1d1", "c2e", "c3", 
    "1ode", "1od1", "1o1e", "1o2", "2de", "2d1", "3e", "4"
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class AbbreviatedWord {
 public:
  string str;
  int start = 0;
  int count = 0;

  AbbreviatedWord(string str, int start, int count) {
    this->str = str;
    this->start = start;
    this->count = count;
  }
};

class GeneralizedAbbreviation {
 public:
  static vector<string> generateGeneralizedAbbreviation(const string &word) {
    vector<string> result;
    int length = word.size();
    queue<AbbreviatedWord> queue;
    queue.push({"", 0, 0});
    while(!queue.empty()){
        AbbreviatedWord current = queue.front();
        queue.pop();
        if(current.start == length){
            if(current.count != 0){
                current.str += to_string(current.count);
            }
            result.push_back(current.str);
        }else{
            queue.push({current.str, current.start + 1, current.count + 1});
            if(current.count != 0){
                current.str += to_string(current.count);
            }
            current.str += word[current.start];
            queue.push({current.str, current.start + 1, 0});
        }
    }//i
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("BAT");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("code");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}

/*
Time Complexity is O(n*2^n)
Space Complexity is O(n*2^n)
*/