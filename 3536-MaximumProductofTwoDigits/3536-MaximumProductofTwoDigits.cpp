// Last updated: 7/25/2026, 9:39:20 PM
1class Solution {
2public:
3    int maxProduct(int n) {
4        int first = 0, second = 0;
5        while (n > 0) {
6            int x = n % 10;
7            if (x > first) {
8                second = first;
9                first = x;
10            } else if (x > second) {
11                second = x;
12            }
13            n /= 10;
14        }
15        return first * second;
16    }
17};