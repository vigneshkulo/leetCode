class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int output = 0;
        unordered_map<int, int> map;
        
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size() - 1; ++col) {
                for (int itr = col + 1; itr < grid[0].size(); ++itr) {
                    if (grid[row][col] == 1 && grid[row][itr] == 1) {
                        int pos = col * 200 + itr;
                        output += map[pos];
                        map[pos] += 1;
                    }
                }
            }
        }
        
        return output;
    }
};
