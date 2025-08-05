// Last updated: 8/5/2025, 4:25:06 PM
class Solution {
public:
    vector<int> findAllSums(vector<int>& nums,int start,int end,int offset){        
        vector<int> res;
        int n=end-start+1;
        for(int i=0;i<(1<<n);++i){
            int sum=0;
            for(int j=0;j<n;++j){
                if(i&(1<<j))
                    sum+=nums[j+offset];
            }
            res.push_back(sum);
        }
        return res;
    }
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> sub1 = findAllSums(nums,0,n/2-1,0);
        vector<int> sub2 = findAllSums(nums,n/2,n-1,n/2);
        sort(sub2.begin(),sub2.end());
        int ans = INT_MAX;
        for(int i=0;i<sub1.size();i++){
            int num1 = sub1[i];
            auto it = lower_bound(sub2.begin(), sub2.end(), goal - num1);

            if (it != sub2.end()) {
                int num2 = *it;
                ans = min(ans, abs(goal - (num1 + num2)));
            }
            if (it != sub2.begin()) {
                --it;
                int num2 = *it;
                ans = min(ans, abs(goal - (num1 + num2)));
            }
        }
        return ans;
    }
};