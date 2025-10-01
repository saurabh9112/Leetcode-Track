// Last updated: 10/1/2025, 8:32:18 PM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0;
        while(numBottles > 0){
            int exchange = numBottles/numExchange;
            if(exchange == 0){
                ans += numBottles%numExchange;
                return ans;
            }
            else{
                ans += numExchange*exchange;
            }
            numBottles = exchange + numBottles%numExchange;
        }
        return ans;
    }
};