class Solution {
public:
    void dfs(int i, int j, int& r1, int& c1, int& r2, int& c2, vector<vector<int>>& land) {
    if (i < 0 || i >= land.size() || j < 0 || j >= land[0].size() || land[i][j] != 1) {
        return;
    }
    if (r1 == -1) { // Update boundary coordinates only if not set yet
        r1 = r2 = i;
        c1 = c2 = j;
    } else { // Update boundary coordinates based on current cell
        r1 = min(r1, i);
        r2 = max(r2, i);
        c1 = min(c1, j);
        c2 = max(c2, j);
    }
    land[i][j] = 2; // Mark cell as visited
    // Continue DFS traversal in all four directions
    dfs(i + 1, j, r1, c1, r2, c2, land);
    dfs(i, j + 1, r1, c1, r2, c2, land);
    dfs(i - 1, j, r1, c1, r2, c2, land);
    dfs(i, j - 1, r1, c1, r2, c2, land);
}

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1){
                    int r1=i,r2=i,c1=j,c2=j;
                    dfs(i,j,r1,c1,r2,c2,land);
                    ans.push_back({r1,c1,r2,c2});
                }
            }
        }
        return ans;
    }
};