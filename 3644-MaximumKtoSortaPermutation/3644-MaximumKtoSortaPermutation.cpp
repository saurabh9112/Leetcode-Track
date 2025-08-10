// Last updated: 8/10/2025, 3:08:01 PM
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n);

        for(int i = 0; i < n; i++) pos[nums[i]] = i;
        
        int minn = INT_MAX;
        for (int i= 0; i < n; i++) {
            if (nums[i] == i) continue;
            int p = pos[i];
            minn = minn & nums[i] & nums[p];
        }

        return minn == INT_MAX ? 0 : minn;
    }
};