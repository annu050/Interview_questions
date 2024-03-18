class Solution {
public:
//to check for different components which are not connected
    bool compo(int start,vector<vector<int>>& graph,vector<int>& color){
        int n=graph.size();
        queue<int>q;
        color[start]=0;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it : graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];//opposite color than the parent
                    q.push(it);
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(compo(i,graph,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};