class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>>& board){
        vis[row][col]=1;
        board[row][col]=0;
        int n=board.size();
        int m=board[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int r=row+dr[i];
            int c=col+dc[i];
            if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && board[r][c]==1){
                dfs(r,c,vis,board);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        //traverse 1st row
        for(int j=0;j<m;j++){
            // 1st row
            if(!vis[0][j] && grid[0][j]==1){
                dfs(0,j,vis,grid);
            }
            // last row
            if(!vis[n-1][j] && grid[n-1][j]==1){
                dfs(n-1,j,vis,grid);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(i,0,vis,grid);
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
                dfs(i,m-1,vis,grid);
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    c++;
                }
            }
        }
        return c;
    }
};