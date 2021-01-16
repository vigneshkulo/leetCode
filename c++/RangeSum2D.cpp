class NumMatrix {
public:
    vector<vector<int>> local;
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() > 0) {
            local = vector<vector<int>>(matrix.size()+1 , vector<int> (matrix[0].size()+1, 0));

            int curSum = 0;
            for (int row = 1; row <= matrix.size(); ++row) {
                for (int col = 1; col <= matrix[0].size(); ++col) {
                    local[row][col] = local[row][col-1] + local[row-1][col] - local[row-1][col-1] + matrix[row-1][col-1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int output = 0;
        
        output += local[row2+1][col2+1];
        output -= local[row2+1][col1];
        output -= local[row1][col2+1];
        output += local[row1][col1];       
            
        return output;
    }
};
