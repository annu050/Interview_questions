class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> diff(r,vector<int>(c));
        //count ones in row and column
        vector<int>row(r);
        vector<int>col(c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                diff[i][j]=row[i]+col[j]-(r-row[i])-(c-col[j]);
               // diff[i][j] = 2 * (row[i] + col[j]) - r - c;
            }
        }
        return diff;

    }
};

