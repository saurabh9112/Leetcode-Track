// Last updated: 2/22/2026, 11:00:59 PM
1class Solution {
2public:
3    int countPrimeSetBits(int left, int right) {
4        int count = 0;
5        
6        for (int i = left; i <= right; i++) {
7            int setBits = __builtin_popcount(i);  // C++ built-in to count set bits
8            if (isPrime(setBits)) {
9                count++;
10            }
11        }
12        return count;
13    }
14    
15private:
16    bool isPrime(int n) {
17        if (n <= 1) {
18            return false;
19        }
20        for (int i = 2; i * i <= n; i++) {
21            if (n % i == 0) {
22                return false;
23            }
24        }
25        return true;
26    }
27};