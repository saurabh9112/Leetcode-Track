// Last updated: 9/7/2026, 12:04:56 AM
1class Solution {
2public:
3    int distinctSubseqII(string s) {
4        const int N = s.length();
5        const int MOD = 1e9 + 7;
6        
7        vector<int> dp(N+1);
8        dp[0] = 1;
9        vector<int> last(26, -1);
10        
11        for(int i = 0; i < N; i++){
12            int x = s[i] - 'a';
13            dp[i+1] = dp[i] * 2 % MOD;
14            if(last[x] >= 0) // if this is the first occurence of ch
15                dp[i+1] -= dp[last[x]];
16            dp[i+1] %= MOD;
17            last[x] = i;
18        }
19        dp[N]--;
20        if(dp[N] < 0) dp[N] += MOD;
21        return dp[N];
22    }
23};