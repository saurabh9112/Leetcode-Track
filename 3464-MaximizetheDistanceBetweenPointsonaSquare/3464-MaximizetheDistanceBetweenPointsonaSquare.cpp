// Last updated: 4/25/2026, 7:40:32 PM
1class Solution {
2public:
3    int maxDistance(int side, vector<vector<int>>& points, int k) {
4        vector<long long> arr;
5
6        for (auto& p : points) {
7            int x = p[0], y = p[1];
8            if (x == 0) {
9                arr.push_back(y);
10            } else if (y == side) {
11                arr.push_back(side + x);
12            } else if (x == side) {
13                arr.push_back(side * 3LL - y);
14            } else {
15                arr.push_back(side * 4LL - x);
16            }
17        }
18        sort(arr.begin(), arr.end());
19
20        auto check = [&](long long limit) -> bool {
21            for (long long start : arr) {
22                long long end = start + side * 4LL - limit;
23                long long cur = start;
24                for (int i = 0; i < k - 1; i++) {
25                    auto it = ranges::lower_bound(arr, cur + limit);
26                    if (it == arr.end() || *it > end) {
27                        cur = -1;
28                        break;
29                    }
30                    cur = *it;
31                }
32                if (cur >= 0) {
33                    return true;
34                }
35            }
36            return false;
37        };
38
39        long long lo = 1, hi = side;
40        int ans = 0;
41        while (lo <= hi) {
42            long long mid = (lo + hi) / 2;
43            if (check(mid)) {
44                lo = mid + 1;
45                ans = mid;
46            } else {
47                hi = mid - 1;
48            }
49        }
50
51        return ans;
52    }
53};