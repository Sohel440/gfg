#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check if a number is prime
bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// Function to find the maximum number of operations
int maxOperations(int l, int r) {
    std::vector<int> primes;
    
    // Collect all primes in the range [l, r]
    for (int i = l; i <= r; ++i) {
        if (isPrime(i)) primes.push_back(i);
    }
    
    // The number of operations is the number of triples we can form
    return primes.size() / 3;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        int result = maxOperations(l, r);
        std::cout << result << std::endl;
    }
    return 0;
}
