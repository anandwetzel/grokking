#include <vector>
#include <iostream>

using namespace std;


bool FindSumOfThree(vector<int> nums, int target)
{
   sort(nums.begin(), nums.end());
   
   for(int current = 0; current < nums.size(); ++current){
      int sum = 0;
      int low = current + 1;
      int high = nums.size() - 1;
      while(low < high){
         sum = nums[current] + nums[low] + nums[high];
         if(sum == target){
            return true;
         }else if(sum < target){
            low++;
         }else{
            high--;
         }
      }
   }
   return false;
}

void Print(vector<int> list){
    for(auto num : list){
        cout << num;
    }
    cout << endl;
}

int main()
{
    std::vector<std::vector<int> > numsLists = {
        {3, 7, 1, 2, 8, 4, 5},
        {-1, 2, 1, -4, 5, -3},
        {2, 3, 4, 1, 7, 9},
        {1, -1, 0},
        {2, 4, 2, 7, 6, 3, 1}};
    std::vector<std::vector<int> > testLists = {
        {10, 20, 21},
        {-8, 0, 7},
        {8, 10, 20},
        {1, -1, 0},
        {8, 11, 15}};
    for (int i = 0; i < numsLists.size(); i++)
    {
        std::cout << (i + 1) << ".\tInput array: ";
        Print(numsLists[i]);
        for (int j = 0; j < testLists[i].size(); j++)
        {
            if (FindSumOfThree(numsLists[i], testLists[i][j]))
                std::cout << " \tSum for " << testLists[i][j] << " exists" << std::endl;
            else
                std::cout << " \tSum for " << testLists[i][j] << " does not exist" << std::endl;
        }
        std::cout << std::string(100, '-') << std::endl;
    }
    return 0;
}

// Time Complexity O(nlogn) sort + O(n^2) search
// Space Complexity O(logn) sort + O(1) search