// Last updated: 9/26/2026, 10:58:04 PM
1class Solution {
2public:
3    string evaluate(string s, vector<vector<string>>& knowledge) {
4        unordered_map<string, string> dict;
5        for (auto& kd : knowledge) {
6            dict[kd[0]] = kd[1];
7        }
8        bool addKey = false;
9        string key, res;
10        for (char c : s) {
11            if (c == '(') {
12                addKey = true;
13            } else if (c == ')') {
14                if (dict.count(key) > 0) {
15                    res += dict[key];
16                } else {
17                    res.push_back('?');
18                }
19                addKey = false;
20                key.clear();
21            } else if (addKey) {
22                key.push_back(c);
23            } else {
24                res.push_back(c);
25            }
26        }
27        return res;
28    }
29};