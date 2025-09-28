// Last updated: 9/28/2025, 9:46:24 PM
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int x) {
        while (r >= l && r < (int)nums.size()) {
            int mid = (l + r) / 2;
            if (nums[mid] >= x)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }

    int triangleNumber(vector<int>& nums) {
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < (int)nums.size() - 1 && nums[i] != 0; j++) {
                k = binarySearch(nums, k, (int)nums.size() - 1, nums[i] + nums[j]);
                count += k - j - 1;
            }
        }
        return count;
    }
};
