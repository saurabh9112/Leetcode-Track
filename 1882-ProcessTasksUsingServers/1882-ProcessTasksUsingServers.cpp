// Last updated: 11/7/2026, 12:08:54 AM
1class Solution {
2private:
3    using PLI = pair<long long, int>;
4    using PII = pair<int, int>;
5
6public:
7    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
8        int m = servers.size();
9        int n = tasks.size();
10
11        // Busy servers, stored as pairs (t, idx)
12        priority_queue<PLI, vector<PLI>, greater<PLI>> busy;
13        // Idle servers, stored as pairs (w, idx)
14        priority_queue<PII, vector<PII>, greater<PII>> idle;
15        for (int i = 0; i < m; ++i) {
16            idle.emplace(servers[i], i);
17        }
18
19        long long ts = 0;
20        // Move servers with t<=ts from priority queue busy to priority queue
21        // idle one by one
22        auto release = [&]() {
23            while (!busy.empty() && busy.top().first <= ts) {
24                auto&& [_, idx] = busy.top();
25                idle.emplace(servers[idx], idx);
26                busy.pop();
27            }
28        };
29
30        vector<int> ans;
31        for (int i = 0; i < n; ++i) {
32            ts = max(ts, static_cast<long long>(i));
33            release();
34            if (idle.empty()) {
35                ts = busy.top().first;
36                release();
37            }
38            auto&& [_, idx] = idle.top();
39            ans.push_back(idx);
40            busy.emplace(ts + tasks[i], idx);
41            idle.pop();
42        }
43        return ans;
44    }
45};