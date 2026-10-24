// Last updated: 10/19/2026, 12:39:24 AM
1class Solution {
2public:
3    int countDaysTogether(string arriveAlice, string leaveAlice,
4                          string arriveBob, string leaveBob) {
5        vector<int> datesOfMonths = {31, 28, 31, 30, 31, 30,
6                                     31, 31, 30, 31, 30, 31};
7        vector<int> prefixSum(1, 0);
8        for (int date : datesOfMonths) {
9            prefixSum.emplace_back(prefixSum.back() + date);
10        }
11
12        int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);
13        int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
14        int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
15        int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
16        return max(0, min(leaveAliceDay, leaveBobDay) -
17                          max(arriveAliceDay, arriveBobDay) + 1);
18    }
19
20    int calculateDayOfYear(const string& day, const vector<int>& prefixSum) {
21        int month = stoi(day.substr(0, 2));
22        int date = stoi(day.substr(3));
23        return prefixSum[month - 1] + date;
24    }
25};