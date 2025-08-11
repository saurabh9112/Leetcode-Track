// Last updated: 8/11/2025, 11:42:03 PM
class Solution {
public:
    long long solve(vector<int>& nums1, vector<int>& nums2,int i,int k,int nums2Min,int sum,vector<vector<int>> &dp){
        if(i == nums1.size()){
            if(k <= 0){
                return sum*nums2Min;
            }
            else{
                return INT_MIN;
            }
        } 
        if(k <= 0) return sum*nums2Min;
        if(dp[i][k] != -1) return dp[i][k];
        long long ans1 = INT_MIN,ans2 = INT_MIN;
        if(nums2Min <= nums2[i]){
            ans1 =  solve(nums1,nums2,i+1,k,nums2Min,sum,dp);
            sum += nums1[i];
            ans2 = solve(nums1,nums2,i+1,k-1,nums2Min,sum,dp);
        }
        else{
            ans1 = solve(nums1,nums2,i+1,k,nums2Min,sum,dp);
            sum += nums1[i];
            ans2 = solve(nums1,nums2,i+1,k-1,nums2[i],sum,dp);
        }
        dp[i][k] = max(ans1,ans2);
        return max(ans1,ans2);
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++){
            nums.push_back({nums2[i],nums1[i]});
        }
        long long currSum = 0;
        sort(nums.rbegin(),nums.rend());
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0;i<k-1;i++){
            currSum += nums[i].second;
            minHeap.push(nums[i].second);
        }
        long long ans = -1;
        for(int i=k-1;i<n;i++){
            currSum += nums[i].second;
            ans = max(ans,(long long)currSum*nums[i].first);
            if(minHeap.size() > 0 && minHeap.top() < nums[i].second){
                currSum -= minHeap.top();
                minHeap.pop();
                minHeap.push(nums[i].second);
            }
            else{
                currSum -= nums[i].second;
            }
        }

        return ans;
    }
};