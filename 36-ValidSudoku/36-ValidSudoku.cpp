// Last updated: 8/30/2025, 1:24:46 PM
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0;i<9;i++){
            vector<int> mp(10,0);
            for(int j=0;j<9;j++){
                char ch = board[i][j];
                if(ch == '.') continue;
                if(mp[ch-'0'] == 1) return false;
                mp[ch-'0'] = 1;
            }
        }
        for(int j=0;j<9;j++){
            vector<int> mp(10,0);
            for(int i=0;i<9;i++){
                char ch = board[i][j];
                if(ch == '.') continue;
                if(mp[ch-'0'] == 1) return false;
                mp[ch-'0'] = 1;
            }
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<int> mp(10,0);
                for(int x=i;x<i+3 && x<9;x++){
                    for(int y=j;y<j+3 && y<9;y++){
                        char ch = board[x][y];
                        if(ch == '.') continue;
                        if(mp[ch-'0'] == 1) return false;
                        mp[ch-'0'] = 1;
                    }
                }
            }
        }
        return true;
    }
};