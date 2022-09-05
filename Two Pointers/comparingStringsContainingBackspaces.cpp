/*
Given two strings containing backspaces (identified by the 
character ‘#’), check if the two strings are equal.

Example 1:
    Input: str1="xy#z", str2="xzz#"             Output: true
    Explanation: After applying backspaces the strings become "xz" and "xz" respectively.
Example 2:
    Input: str1="xy#z", str2="xyz#"             Output: false
    Explanation: After applying backspaces the strings become "xz" and "xy" respectively.
Example 3:
    Input: str1="xp#", str2="xyz##"             Output: true
    Explanation: After applying backspaces the strings become "x" and "x" respectively.
    In "xyz##", the first '#' removes the character 'z' and the second '#' removes the character 'y'.
Example 4:
    Input: str1="xywrrmp", str2="xywrrmu#p"     Output: true
    Explanation: After applying backspaces the strings become "xywrrmp" and "xywrrmp" respectively.
*/

#include <iostream>
#include <string>

using namespace std;

class BackspaceCompare {
 public:
  static bool compare(const string &str1, const string &str2) {
    int end1 = str1.size() - 1, end2 = str2.size() - 1;
    while(end1 >= 0){
      int i1 = nextIndex(str1, end1);
      int i2 = nextIndex(str2, end2);
    
      if(i1 < 0 && i2 < 0)return true;
      else if(i1 < 0 || i2 < 0) return false;
      if(str1[i1] != str2[i2]) return false;
      
      end1 = i1 - 1;
      end2 = i2 - 1;
    }
    return true;
  }
 private:
  static int nextIndex(const string &str, int index){
    int counter = 0;
    while(index >= 0){
      if(str[index] == '#') counter++;
      else if(counter > 0) counter--;
      else break;
      index--;
    }
    return index;
  }
};

int main(int argc, char *argv[]) {
  cout << BackspaceCompare::compare("xy#z", "xzz#") << endl;
  cout << BackspaceCompare::compare("xy#z", "xyz#") << endl;
  cout << BackspaceCompare::compare("xp#", "xyz##") << endl;
  cout << BackspaceCompare::compare("xywrrmp", "xywrrmu#p") << endl;
}

/*
Time Complexity is O(n)
Space Complexity is O(1)
*/