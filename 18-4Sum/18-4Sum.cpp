// Last updated: 8/13/2025, 7:18:15 PM
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
        // vector<vector<int>> ans;
        // vector<int> currArr;
        // solve(nums, 0, (long long)target, currArr, ans, 4);
        // return ans;
        set<vector<int>> ans;
        int size = nums.size();
        for(int i=0;i<size-3;i++){
            for(int j=i+1;j<size-2;j++){
                int left = j+1;
                int right = size-1;
                long long a = nums[i],b = nums[j];
                long long diff = target - (a+b);
                while(left < right && left < size && right >= 0){
                    long long add = nums[left] + nums[right];
                    if(add == diff){
                        vector<int> arr;
                        arr.push_back(a);
                        arr.push_back(b);
                        arr.push_back(nums[left]);
                        arr.push_back(nums[right]);
                        ans.insert(arr);
                        right--;
                        left++;
                    }
                    else if(add > diff){
                        right--;
                    }
                    else{
                        left++;
                    }
                }
            }
        }

        vector<vector<int>> result;
        for(auto arr:ans){
            result.push_back(arr);
        }
        return result;
    }
};
