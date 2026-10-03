// Last updated: 10/3/2026, 11:21:46 PM
1class Solution {
2public:
3    bool isValid(string s) {
4        stack<char> st;
5        unordered_map<char,char> mp;
6        mp['('] = ')';
7        mp['{'] = '}';
8        mp['['] = ']';
9        for (char c : s) {
10            if (c == '(' || c == '{' || c == '[') {
11                st.push(c);
12            } else {
13                if (st.empty() || c != mp[st.top()]){
14                    return false;
15                }
16                st.pop();
17            }
18        }
19        return st.empty();
20    }
21};