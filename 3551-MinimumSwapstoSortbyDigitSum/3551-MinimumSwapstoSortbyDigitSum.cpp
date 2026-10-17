// Last updated: 10/17/2026, 10:20:48 PM
1class Solution {
2public:
3    int minSwaps(vector<int>& nums) {
4        int n = nums.size();
5        vector<int> digitSum(n);
6        for (int i = 0; i < n; i++) {
7            int x = nums[i], sum = 0;
8            while (x > 0) {
9                sum += x % 10;
10                x /= 10;
11            }
12            digitSum[i] = sum;
13        }
14
15        vector<int> indices(n);
16        iota(indices.begin(), indices.end(), 0);
17        sort(indices.begin(), indices.end(), [&](int a, int b) {
18            if (digitSum[a] != digitSum[b]) {
19                return digitSum[a] < digitSum[b];
20            }
21            return nums[a] < nums[b];
22        });
23
24        vector<int> targetPos(n);
25        for (int pos = 0; pos < n; pos++) {
26            targetPos[indices[pos]] = pos;
27        }
28
29        vector<int> visited(n);
30        int cycles = 0;
31        for (int i = 0; i < n; i++) {
32            if (!visited[i]) {
33                cycles++;
34                int j = i;
35                while (!visited[j]) {
36                    visited[j] = true;
37                    j = targetPos[j];
38                }
39            }
40        }
41
42        return n - cycles;
43    }
44};