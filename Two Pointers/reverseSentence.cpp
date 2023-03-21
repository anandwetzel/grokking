#include <string>
#include <vector>
#include <iostream>

using namespace std;

string ReverseWords(string sentence)
{
    reverse(sentence.begin(), sentence.end());

    int start = 0, end = 0;
    while(true){
        while(start < sentence.size() && sentence[start] == ' '){
            ++start;
        }
        if(start == sentence.size()) break;
        end = start + 1;
        while(end < sentence.size() && sentence[end] != ' '){
            ++end;
        }
        int temp = end;
        --end;
        while(start < end){
            char temp = sentence[start];
            sentence[start] = sentence[end];
            sentence[end] = temp;
            ++start;
            --end;
        }
        end = temp;
        start = end;
    }

    return sentence;
}

int main()
{
    std::vector<std::string> stringsToReverse = {
        " Hello World ",
        "We love Python",
        "The quick brown fox jumped over the lazy dog",
        "Hey",
        "To be, or not to be",
        "AAAAA",
        " Hello     World "};
    for (int i = 0; i < stringsToReverse.size(); i++)
    {
        std::cout << (i + 1) << ".\tActual string:\t\t" << stringsToReverse[i] << std::endl;
        std::string result = ReverseWords(stringsToReverse[i]);
        std::cout << "\tReversed string:\t" << result << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
}

// Time Complexity O(n)
// Space Complexity O(1)