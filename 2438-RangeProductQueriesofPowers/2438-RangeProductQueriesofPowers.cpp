// Last updated: 8/11/2025, 11:47:34 AM
class Solution {
public:
    vector<int> formPowers(int n){
        vector<int> powers;
        string s = "";
        while(n > 0){
            int rem = n%2;
            if(rem != 0){
                s += "1";
            }
            else{
                s += "0";
            }
            n /= 2;
        }
        int cnt = 0;
        for(auto i:s){
            int num = (i - '0')*pow(2,cnt++);
            if(num != 0) powers.push_back(num);
        }
        return powers;
    }
    long long modPow(long long base, long long exp, int MOD) {
        long long res = 1;
        while(exp > 0) {
            if(exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7; 
        vector<int> powers = formPowers(n);
        vector<int> prefixProd;
        prefixProd.push_back(1);
        long long prod = 1;
        for(int i=0;i<powers.size();i++){
            prod = (prod%MOD) * (powers[i]%MOD) % MOD;
            prefixProd.push_back(prod);
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int left = queries[i][0];
            int right = queries[i][1];
            left++;
            right++;
            long long inv = modPow(prefixProd[left-1], MOD-2, MOD); // modular inverse
            int p = (prefixProd[right] * inv) % MOD;
            ans.push_back(p);
        }
        return ans;
    }
};