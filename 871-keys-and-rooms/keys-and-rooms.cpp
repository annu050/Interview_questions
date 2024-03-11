class Solution {
public:
    void dfs(vector<vector<int>>& rooms,int src,vector<bool> &visited){
        visited[src]=true;
        for(int &node: rooms[src]){
            if(!visited[node]){
                dfs(rooms,node,visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visited(n,false);
        dfs(rooms,0,visited);
        for(bool x:visited){
            if(x==false){//ek bhi visit nahi hua to return false
                return false;
            }
        }
        return true;
    }
};