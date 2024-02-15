class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        vector<int>common(26,INT_MAX);
        for(auto s:words){
            vector<int>cnt(26,0);
            for(auto p:s){
                cnt[p-'a']++;
            }
            for(int i=0;i<26;i++){
                common[i]=min(common[i],cnt[i]);
            }
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<common[i];j++){
                ans.push_back(string(1,i+'a'));
            }
         }
       return ans;
    }
};