class Solution {
public:
    void dfs(int node,vector<int> adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //convert adjacency matrix to list
        int v=isConnected.size(); 
        vector<int>adj[v];
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
       vector<int>vis(v,0);
        int cnt=0;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                cnt++;//we have to start from 3 different nodes 
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};