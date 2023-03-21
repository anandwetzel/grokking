#include <iostream>
#include <vector>

int sum_squared(int n){
    int sum = 0;
    while(n > 0){
        int temp = n % 10;
        sum += temp * temp;
        n /= 10;
    }
    return sum;
}

bool IsHappyNumber(int n){
    if(n == 1) return true;
    int slow = n;
    int fast = sum_squared(n);
    while(fast != slow){
        if(fast == 1) return true;
        slow = sum_squared(slow);
        fast = sum_squared(sum_squared(fast));
    }
    return false;
}

int main() {
    std::cout << "\tInput Number: " << 25 << "\n";      // False
    std::cout << IsHappyNumber(25) << "\n";
    std::cout << "\tInput Number: " << 1 << "\n";       // True
    std::cout << IsHappyNumber(1) << "\n";
    std::cout << "\tInput Number: " << 5759 << "\n";    // False
    std::cout << IsHappyNumber(5759) << "\n";
    std::cout << "\tInput Number: " << 19 << "\n";      // True
    std::cout << IsHappyNumber(19) << "\n";
}

// Time Complexity O(logn + logn)
// Space Complexity O(1)