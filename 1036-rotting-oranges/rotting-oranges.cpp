class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<pair<int,int>,int>>q;//r,c,time
       int n=grid.size();
       int m=grid[0].size();
       int fresh=0;
       int vis[n][m];//new array to store the no.s after updation
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
       }
       int tm=0;
       int cnt=0;
       int dr[]={-1,0,1,0};
       int dc[]={0,1,0,-1};
       while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            for(int i=0;i<4;i++){
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1 ){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    cnt++;
                }
            }
       }
       if(cnt!=fresh)return -1;
       
       return tm;


    }
};