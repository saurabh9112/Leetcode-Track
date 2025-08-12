// Last updated: 8/12/2025, 7:38:17 PM
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        int n = costs.size();
        priority_queue<int,vector<int>,greater<int>> minHeapSt;
        priority_queue<int,vector<int>,greater<int>> minHeapEd;
        int i = 0, j = n - 1;
        for (int cnt = 0; cnt < candidates && i <= j; cnt++) {
            minHeapSt.push(costs[i++]);
        }
        for (int cnt = 0; cnt < candidates && i <= j; cnt++) {
            minHeapEd.push(costs[j--]);
        }
        while (k > 0) {
            int num1 = minHeapSt.empty() ? INT_MAX : minHeapSt.top();
            int num2 = minHeapEd.empty() ? INT_MAX : minHeapEd.top();
            if (num1 <= num2) {
                ans += num1;
                minHeapSt.pop();
                if (i <= j) minHeapSt.push(costs[i++]);
            } else {
                ans += num2;
                minHeapEd.pop();
                if (i <= j) minHeapEd.push(costs[j--]);
            }
            k--;
        }
        return ans;
    }
};
