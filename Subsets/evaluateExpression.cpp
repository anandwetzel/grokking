/*
Given an expression containing digits and operations 
(+, -, *), find all possible ways in which the 
expression can be evaluated by grouping the numbers 
and operators using parentheses.

Example 1:
    Input: "1+2*3"      Output: 7, 9
    Explanation: 1+(2*3) => 7 and (1+2)*3 => 9
Example 2:
    Input: "2*3-4-5"    Output: 8, -12, 7, -7, -3 
    Explanation: 2*(3-(4-5)) => 8, 2*(3-4-5) => -12, 2*3-(4-5) 
    => 7, 2*(3-4)-5 => -7, (2*3)-4-5 => -3
*/

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class EvaluateExpression {
 public:
  static vector<int> diffWaysToEvaluateExpression(const string& input) {
    vector<int> result;
    if(input.find("+") == string::npos && input.find("-") == string::npos 
            && input.find("*") == string::npos){
        result.push_back(stoi(input));
    }else{
        for(int i = 0; i < input.length(); ++i){
            char chr = input[i];
            if(!isdigit(chr)){
                vector<int> left = diffWaysToEvaluateExpression(input.substr(0,i));
                vector<int> right = diffWaysToEvaluateExpression(input.substr(i+1));
                for(auto x : left){
                    for(auto y : right){
                        if(chr == '+') result.push_back(x + y);
                        else if(chr == '-') result.push_back(x - y);
                        else if(chr == '*') result.push_back(x * y);
                    }
                }
            }
        }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = EvaluateExpression::diffWaysToEvaluateExpression("1+2*3");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = EvaluateExpression::diffWaysToEvaluateExpression("2*3-4-5");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}

/*
Time Complexity is O(4^n / n^(1/2))
Space Complexity is O(4^n / n^(1/2))
*/