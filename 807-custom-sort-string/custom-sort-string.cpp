class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> ans;
        for(int i=0;i<order.length();i++){
            ans[order[i]]=i+1;
        }
        sort(s.begin(),s.end(),[&](char a,char b){return ans[a]<ans[b];});
        return s;
    }
};