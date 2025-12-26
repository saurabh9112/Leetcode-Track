// Last updated: 12/26/2025, 2:24:51 AM
1class Solution {
2public:
3    int bestClosingTime(string customers) {
4        // Start with closing at hour 0 and assume the current penalty is 0.
5        int minPenalty = 0, curPenalty = 0;
6        int earliestHour = 0;
7
8        for (int i = 0; i < customers.size(); i++) {
9            char ch = customers[i];
10
11            // If status in hour i is 'Y', moving it to open hours decrement
12            // penalty by 1. Otherwise, moving 'N' to open hours increment
13            // penatly by 1.
14            if (ch == 'Y') {
15                curPenalty--;
16            } else {
17                curPenalty++;
18            }
19
20            // Update earliestHour if a smaller penatly is encountered.
21            if (curPenalty < minPenalty) {
22                earliestHour = i + 1;
23                minPenalty = curPenalty;
24            }
25        }
26
27        return earliestHour;
28    }
29};