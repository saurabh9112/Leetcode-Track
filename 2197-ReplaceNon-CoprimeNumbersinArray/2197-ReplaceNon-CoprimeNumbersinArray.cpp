// Last updated: 9/16/2025, 6:24:32 PM
class Solution {
public:
    static int lcm(int x, int y) {
        return x/gcd(x, y)*y;
    }

    static vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            int cur=x;
            while (st.size()) {
                int g=gcd(st.back(), cur);
                if (g==1) break;
                cur=lcm(st.back(), cur);
                st.pop_back();
            }
            st.push_back(cur);
        }

        return st;
    }
};