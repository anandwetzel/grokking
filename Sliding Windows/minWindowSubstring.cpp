#include <climits>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string MinWindow(string s, string t){
    if(t.empty()) return "";    
    std::map<char, int> count{}, window{};
    for(char c : t){
        count[c]++;
    }
    int current = 0, required = count.size();
    std::vector<int> res{};
    int length = INT_MAX, l = 0;
    for (int i = 0; i < s.size(); i++)
    {
        window[s[i]]++;
        if(count.find(s[i]) != count.end() && window[s[i]] == count[s[i]]){
            current++;
        }
        while(current == required){
            if((i - l + 1) < length){
                res = {l, i};
                length = i - l + 1;
            }
            window[s[l]]--;
            if(count.find(s[l]) != count.end() && window[s[l]] < count[s[l]]){
                current--;
            }
            l++;
        }
    }
    l = res[0];
    return (length != INT_MAX) ? s.substr(l, length) : "";
}

int main()
{
    std::vector<std::string> s = {"PATTERN", "LIFE", "ABRACADABRA", "STRIKER", "DFFDFDFVD"};
    std::vector<std::string> t = {"TN", "I", "ABC", "RK", "VDD"};
    for (int i = 0; i < s.size(); i++)
    {
        std::cout << i + 1 << ".\ts: " << s[i] << "\n\tt: " << t[i]
                  << "\n\tThe minimum substring containing " << t[i]
                  << " is: " << MinWindow(s[i], t[i]) << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
}