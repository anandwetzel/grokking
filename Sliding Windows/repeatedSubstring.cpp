#include <set>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

set<string> FindRepeatedSequences(string s, int k)
{
    if(k >= s.length()) return {};
    set<string> answer;
    unordered_map<string, int> map;
    for(int start = 0; start < s.length() - k; start++){
        string sub = s.substr(start, k);
        if(map.find(sub) != map.end()) answer.insert(sub);
        map[sub] = start;
    }

    return answer;
}

int main()
{
    std::vector<std::string> inputsString = {
        "ACGT", "AGACCTAGAC", "AAAAACCCCCAAAAACCCCCC",
        "GGGGGGGGGGGGGGGGGGGGGGGGG", "TTTTTCCCCCCCTTTTTTCCCCCCCTTTTTTT",
        "TTTTTGGGTTTTCCA", "", "AAAAAACCCCCCCAAAAAAAACCCCCCCTG", "ATATATATATATATAT"};
    std::vector<int> inputsK = {3, 3, 8, 12, 10, 14, 10, 10, 6};

    for (int i = 0; i < inputsK.size(); i++)
    {
        std::cout << i + 1 << ".\tInput Sequence: '" << inputsString[i] << "'\n";
        set<string> answer = FindRepeatedSequences(inputsString[i], inputsK[i]);
        auto itr = answer.begin();
        for(int j = 0; j < answer.size(); ++j){
            cout << *itr++ << " ";
        }
        std::cout << "\tk: " << inputsK[i] << "\n";
    }
}

// Time Complexity O(n)
// Space Complexity O(n - k)