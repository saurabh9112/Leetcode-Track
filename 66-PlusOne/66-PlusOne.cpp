// Last updated: 12/31/2025, 11:25:23 PM
1class Solution {
2public:
3    vector<int> plusOne(vector<int>& v) {
4        int n = v.size();
5        for(int i = n-1; i >= 0; i--){
6            if(i == n-1)
7                v[i]++;
8            if(v[i] == 10){
9                v[i] = 0;
10                if(i != 0){
11                    v[i-1]++;
12                }
13                else{
14                    v.push_back(0);
15                    v[i] = 1;
16                }
17            }
18        }
19        return v;
20    }
21};