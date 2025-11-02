// Last updated: 11/1/2025, 2:19:12 PM
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        
        // Mark walls as 3
        for (auto& wall : walls) {
            grid[wall[0]][wall[1]] = 3;
        }
        
        // Mark guards as 2
        for (auto& guard : guards) {
            grid[guard[0]][guard[1]] = 2;
        }

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Mark covered areas
        for (auto& guard : guards) {
            for (auto& dir : directions) {
                int x = guard[0] + dir.first;
                int y = guard[1] + dir.second;
                
                while (x >= 0 && x < m && y >= 0 && y < n) {
                    if (grid[x][y] == 2 || grid[x][y] == 3) break; // Stop at guard or wall
                    if (grid[x][y] == 0) grid[x][y] = 1; // Mark as covered
                    x += dir.first;
                    y += dir.second;
                }
            }
        }
        
        // Count unguarded cells
        int unguarded = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) ++unguarded;
            }
        }
        
        return unguarded;
    }
};