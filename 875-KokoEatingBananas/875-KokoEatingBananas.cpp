// Last updated: 8/10/2025, 2:17:44 PM
class Solution {
public:
    bool isPoss(long long bananas, vector<int> &piles, int hours) {
        long long cntHrs = 0;
        for (int pile : piles) {
            cntHrs += (pile + bananas - 1) / bananas; // integer ceil
            if (cntHrs > hours) return false; // early exit for speed
        }
        return cntHrs <= hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = 0;
        for (int pile : piles) {
            maxPile = max(maxPile, pile);
        }
        int left = 1, right = maxPile;
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isPoss(mid, piles, h)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
