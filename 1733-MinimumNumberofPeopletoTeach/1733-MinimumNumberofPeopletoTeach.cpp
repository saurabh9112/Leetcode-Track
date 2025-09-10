// Last updated: 9/10/2025, 2:08:10 PM
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        
        // put each user's languages into a set for quick lookup
        vector<unordered_set<int>> knows(m);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i].insert(lang);
            }
        }

        // find all users involved in "conflicts" (can't talk)
        unordered_set<int> conflictUsers;
        for (auto &f : friendships) {
            int u = f[0] - 1;
            int v = f[1] - 1;
            bool canTalk = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if (!canTalk) {
                conflictUsers.insert(u);
                conflictUsers.insert(v);
            }
        }

        // if no conflict, answer is 0
        if (conflictUsers.empty()) return 0;

        // try teaching each language -> compute min
        int ans = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int teachCount = 0;
            for (int user : conflictUsers) {
                if (!knows[user].count(lang)) {
                    teachCount++;
                }
            }
            ans = min(ans, teachCount);
        }

        return ans;
    }
};
