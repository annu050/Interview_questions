class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> s;
        for(int i=0;i<paths.size();i++){
            s.insert(paths[i][0]);
        }
        string ans ="";
        for(int i=0;i<paths.size();i++){
            if(s.find(paths[i][1])==s.end()){
                ans=paths[i][1];
            }
        }
        return ans;
    }
};