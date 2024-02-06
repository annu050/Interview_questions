class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>> mp;
        for(auto s:strs){
            string i=s;
            sort(i.begin(),i.end());
            mp[i].push_back(s);
        }
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};