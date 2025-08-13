// Last updated: 8/13/2025, 7:01:07 PM
class Solution {
public:
    void solve(vector<int>& nums, int index, long long target, vector<int>& currArr, vector<vector<int>>& ans, int k) {
        if (k == 0) {
            if (target == 0) ans.push_back(currArr);
            return;
        }
        if (index >= nums.size()) return;

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;

            currArr.push_back(nums[i]);
            solve(nums, i + 1, target - (long long)nums[i], currArr, ans, k - 1);
            currArr.pop_back();
        }
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> currArr;
        solve(nums, 0, (long long)target, currArr, ans, 4);
        return ans;
    }
};
