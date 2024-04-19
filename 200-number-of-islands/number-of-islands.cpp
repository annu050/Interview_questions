class Solution {
public:
   
    int numIslands(vector<vector<char>>& grid) {
       
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);//check one area fully till we have no connection of 1
                    count++;// after that count
                }
            }
        }
        return count;
    }
     void dfs(vector<vector<char>>& grid,int i,int j){
         int r=grid.size();
        int c=grid[0].size();
        if(i<0  ||i==r|| j<0||j==c|| grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';//put one to zero so that when we search again for one we don't get same one in that 
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
};