class Solution {
public:
    void dfs(vector<vector<int>> &grid,int &ans,int i,int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
            return;
        grid[i][j]=-1;
        ans+=(j + 1 >= grid[0].size() || grid[i][j+1] == 0) /* right */ +
                (i - 1 < 0            || grid[i-1][j] == 0) /* top */ +
                (j - 1 < 0            || grid[i][j-1] == 0) /* left */ +
                (i + 1 >= grid.size()    || grid[i+1][j] == 0) /* bottom */;
        dfs(grid,ans,i,j+1);
        dfs(grid,ans,i-1,j);
        dfs(grid,ans,i,j-1);
        dfs(grid,ans,i+1,j);
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    dfs(grid,ans,i,j);
                    return ans;
                }
            }
        }
        return 0;
    }
};