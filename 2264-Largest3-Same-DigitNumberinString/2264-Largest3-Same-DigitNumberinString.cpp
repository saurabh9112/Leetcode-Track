// Last updated: 8/14/2025, 3:08:01 PM
class Solution {
public:
    string largestGoodInteger(string num) {
        int size = num.size();
        string result = "";
        for(int i=1;i<size-1;i++){
            if(num[i] == num[i+1] && num[i] == num[i-1]){
                string ans = num.substr(i-1,3);
                if(result.size() == 0 || stoi(result) < stoi(ans)){
                    result = ans;
                }
            }
        }
        return result;
    }
};