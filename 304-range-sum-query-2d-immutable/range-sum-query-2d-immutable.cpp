class NumMatrix {
public:
    vector<vector<int>>p;
    NumMatrix(vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        p = vector<vector<int>>(m + 1, vector<int>(n + 1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                p[i][j]=matrix[i-1][j-1]+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // as p start from 1 so increse these
        row1++;
        col1++;
        row2++;
        col2++;
        return p[row2][col2]-p[row2][col1-1]-p[row1-1][col2]+p[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */