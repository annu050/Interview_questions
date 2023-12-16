class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.length()<s.length()|| t.length()>s.length()){
            return false;
        }
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(mp.find(t[i])==mp.end()){
                return false;
            }
            mp[t[i]]--;
            if(mp[t[i]]<0){
                return false;
            }
        }
        return true;
    }
};