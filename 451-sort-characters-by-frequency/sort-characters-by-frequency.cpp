class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>l;
        for(int i=0;i<s.size();i++){
           l[s[i]]++;
        }
        priority_queue<pair<int,char>> q;
        for(auto [a,fre]:l)q.push({fre,a});
        string ans="";
        pair<int,char>temp;
        while(!q.empty()){
            temp=q.top();
            q.pop();
            ans+=string(temp.first,temp.second);
        }
        return ans;
    }
};