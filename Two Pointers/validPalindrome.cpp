#include <string>
#include <iostream>

using namespace std;

bool IsPalindrome(string inputString)
{
    int ptr1 = 0;
    int ptr2 = inputString.size() - 1;
    while(ptr1 < ptr2){
        if(inputString[ptr1] != inputString[ptr2]) return false;
        ptr1++;
        ptr2--;
    }
    return true;
}

int main(){
    cout << IsPalindrome("abbbba") << "\n"; // true
    cout << IsPalindrome("creec") << "\n"; // false
}

// Time complexity O(n)
// Space complexity O(1)