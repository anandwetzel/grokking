#include <climits>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string MinWindow(string str1, string str2){
    int index1 = 0, index2 = 0, size = INT_MAX;
    string result = "";
    while(index1 < str1.length()){
        if(str1[index1] == str2[index2]){
            index2++;
            if (index2 == str2.length()){
                index2--;
                int start = index1, end = index1 + 1;
                while(index2 >= 0){
                    if (str1[start] == str2[index2])index2--;
                    start--;
                }
                start++;
                if(end - start < size){
                    size = end - start;
                    result = str1.substr(start, size);
                }
                index1 = start;
                index2 = 0;
            }
        }
        index1++;
    }
    
    return result;
}

int main()
{
    std::vector<std::string> str1 = {"abcdebdde", "fgrqsqsnodwmxzkzxwqegkndaa",
                                              "qwewerrty", "aaabbcbq", "zxcvnhss", "alpha",
                                              "beta", "asd", "abcd"};

    std::vector<std::string> str2 = {"bde", "kzed", "werty", "abc", "css", "la", "ab", "as", "pp"};

    for (int i = 0; i < str1.size(); i++)
    {
        std::cout << (i + 1) << ".\tInput strings: (" << str1[i] << ", " << str2[i] << ")" << std::endl;
        std::cout << "\tSubsequence string: " << MinWindow(str1[i], str2[i]) << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
}