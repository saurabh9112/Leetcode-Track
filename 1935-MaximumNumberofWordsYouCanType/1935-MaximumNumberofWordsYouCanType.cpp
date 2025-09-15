// Last updated: 9/15/2025, 1:16:26 PM
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> mp;
        for(auto i:brokenLetters) mp[i] = 1;
        int cnt = 0;
        int size = text.size();
        int i = 0;
        while(i<size){
            int j = i;
            bool flag = true;
            while(j < size && text[j] != ' '){
                if(mp[text[j]] == 1){
                    flag = false;
                }
                j++;
            }
            if(flag) cnt++;
            i = j+1;
        }
        return cnt;
    }
};