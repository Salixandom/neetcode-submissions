class NumMatrix {
    vector<vector<int>> prefixSumMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        prefixSumMatrix = vector<vector<int>>(rows, vector<int>(cols, 0));

        for(int i = 0; i < rows; i++) {
            prefixSumMatrix[i][0] = matrix[i][0];
            for(int j = 1; j < cols; j++) {
                prefixSumMatrix[i][j] = prefixSumMatrix[i][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i <= row2; i++) {
            if(col1 > 0) {
                sum += prefixSumMatrix[i][col2] - prefixSumMatrix[i][col1 - 1];
            } else {
                sum += prefixSumMatrix[i][col2];
            }
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */