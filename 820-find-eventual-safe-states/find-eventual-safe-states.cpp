class Solution {
public:
    bool dfs(int node,vector<vector<int>>& graph,vector<int>&vis,vector<int>&pathvis,vector<int>& check){
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(int it:graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,pathvis,check)){
                    check[node]=0;
                    return true;
                }
            }
            else if(pathvis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathvis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //anyone who is a part of cycle i.e any incoming edges to cycle and anyone who leads to to a cycle cannot be a safe node
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>pathvis(n,0);
        vector<int>checks(n,0);//mark the safe nodes
        vector<int>safenodes;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,pathvis,checks);
            }
        }
        for(int i=0;i<n;i++){
            if(checks[i]==1)safenodes.push_back(i);
        }
        return safenodes;
    }
};