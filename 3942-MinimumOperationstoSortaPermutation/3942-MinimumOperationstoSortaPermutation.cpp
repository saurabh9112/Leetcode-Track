// Last updated: 10/31/2026, 3:36:36 PM
1class Solution {
2public:
3    int minOperations(vector<int>& nums) {
4        const int n = nums.size();
5        if (n == 1) {
6            return 0;
7        }
8
9        const int start = find(nums.begin(), nums.end(), 0) - nums.begin();
10        bool asc = true;
11        bool desc = true;
12
13        for (int i = 1; i < n; i++) {
14            const int value = nums[(start + i) % n];
15
16            if (value != i) {
17                asc = false;
18            }
19            if (value != n - i) {
20                desc = false;
21            }
22
23            if (!asc && !desc) {
24                return -1;
25            }
26        }
27
28        if (asc) {
29            return min(start, n - start + 2);
30        }
31
32        return min(n - start, start + 2);
33    }
34};