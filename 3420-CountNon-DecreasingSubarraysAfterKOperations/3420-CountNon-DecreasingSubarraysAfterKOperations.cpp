// Last updated: 11/14/2026, 1:15:19 AM
1class Solution {
2public:
3    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
4        int n = nums.size();
5        long long ans = 0;
6        long long operations = 0;
7        // Maintain the window maximum with a priority queue
8        priority_queue<pair<int, int>> q;
9        // Record the set of elements covered by this index
10        vector<vector<int>> cnt(n);
11        // Index of the first greater-or-equal element to the right
12        vector<int> pos(n, n);
13        // Decreasing monotonic stack
14        stack<int> st;
15
16        for (int left = 0, right = 0; right < n; right++) {
17            // Maintain the monotonic stack
18            while (!st.empty() && nums[right] >= nums[st.top()]) {
19                pos[st.top()] = right;
20                st.pop();
21            }
22            // The stack top is the nearest greater element to the left of
23            // nums[right]
24            if (!st.empty()) {
25                cnt[st.top()].push_back(right);
26            }
27            st.push(right);
28
29            // The priority queue front is the window maximum
30            q.emplace(nums[right], right);
31            // Adding nums[right] increases the operation count
32            operations += max(0, q.top().first - nums[right]);
33
34            // The minimum operation count exceeds k; shrink the window
35            while (operations > k) {
36                // Removing nums[left] from the window decreases the operation
37                // count
38                for (int i : cnt[left]) {
39                    // Subtract the contribution
40                    operations -=
41                        (long long)(nums[left] - nums[i]) *
42                        (min(pos[i], right + 1) - i);
43                }
44                left++;
45            }
46
47            // Remove elements with indices less than left from the priority
48            // queue
49            while (!q.empty() && q.top().second < left) {
50                q.pop();
51            }
52
53            // There are right - left + 1 valid contiguous subarrays ending at
54            // right
55            ans += right - left + 1;
56        }
57
58        return ans;
59    }
60};