#include <string>
#include <iostream>

using namespace std;

bool validPalindrome(string arr)
{
    int start = 0;
    int end = arr.size() - 1;
    int mismatch = 0;
    while(start < end){
        if(arr[start] != arr[end] && mismatch == 0){
            ++start;
            mismatch = 1;
        }else if(arr[start] != arr[end] && mismatch == 1){
            --start;
            --end;
            mismatch = 2;
        }else if(arr[start] != arr[end] && mismatch == 2){
            return false;
        }else{
            --end;
            ++start;
        }
    }
    return true;
}

int main(){
    cout << validPalindrome("abbcba") << "\n"; // true
    cout << validPalindrome("creec") << "\n"; // true
    cout << validPalindrome("zxcvbn") << "\n"; // false
}

// Time complexity O(n)
// Space complexity O(1)