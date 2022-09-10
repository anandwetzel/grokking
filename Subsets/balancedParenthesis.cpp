/*
For a given number ‘N’, write a function to generate 
all combination of ‘N’ pairs of balanced parentheses.

Example 1:
    Input: N=2
    Output: (()), ()()
Example 2:
    Input: N=3
    Output: ((())), (()()), (())(), ()(()), ()()()
*/

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class ParenthesisStr {
 public:
    string str;
    int numOpen = 0;
    int numClosed = 0;

    ParenthesisStr (const string &s, int numOpen, int numClosed){
        this->str = s;
        this->numClosed = numClosed;
        this->numOpen = numOpen;
    }
};

class GenerateParentheses {
 public:
  static vector<string> generateValidParentheses(int num) {
    vector<string> result;
    queue<ParenthesisStr> queue;
    queue.push({"", 0, 0});
    while(!queue.empty()){
        ParenthesisStr str = queue.front();
        queue.pop();
        if(str.numOpen == num && str.numClosed == num){
            result.push_back(str.str);
        }else{
            if (str.numOpen < num) { 
                queue.push({str.str + "(", str.numOpen + 1, str.numClosed});
            }
            if (str.numOpen > str.numClosed) {
                queue.push({str.str + ")", str.numOpen, str.numClosed + 1});
            }
        }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GenerateParentheses::generateValidParentheses(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParentheses::generateValidParentheses(3);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}

/*
Time Complexity is O(n*2^n)
Space Complexity is O(n*2^n)
*/