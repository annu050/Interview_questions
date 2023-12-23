class Solution {
public:
    bool isPathCrossing(string path) {
        vector<pair<int,int>>vis;
        int x=0,y=0;
        vis.push_back({x,y});
        for(auto it:path){
            if(it=='N')y++;
            else if(it=='S')y--;
            else if(it=='W')x--;
            else if(it=='E')x++;
            vis.push_back({x,y});
        }
        set<pair<int,int>>st(vis.begin(),vis.end());
        if(vis.size()==st.size())return false;
        else return true;


    }
};