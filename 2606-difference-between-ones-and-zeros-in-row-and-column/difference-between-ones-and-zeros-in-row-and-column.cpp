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

        // int row = grid.size(); // Get the number of rows in the grid
        // int col = grid[0].size(); // Get the number of columns in the grid

        // vector<vector<int>> diff(row, vector<int>(col)); // Create a matrix to store differences

        // vector<int> r(row); // Create a vector to store counts of ones in each row
        // vector<int> c(col); // Create a vector to store counts of ones in each column

        // // Calculate counts of ones in rows and columns
        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
        //         r[i] += grid[i][j]; // Sum the elements in each row
        //         c[j] += grid[i][j]; // Sum the elements in each column
        //     }
        // }

        // Calculate the difference between the count of ones and zeros in rows and columns
        // for(int i = 0; i < row; i++){
        //     for(int j = 0; j < col; j++){
        //         // Calculate the difference using the formula: 2 * (count of ones in row i + count of ones in column j) - (total row count + total column count)
        //         diff[i][j] = 2 * (r[i] + c[j]) - row - col;
        //     }
        // }

        // return diff; // Return the matrix containing differences
    }
};

