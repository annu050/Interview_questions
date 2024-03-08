class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int maxf=0;
        for(auto x:mp){
            if(x.second>maxf){
                maxf=x.second;
            }
        }
        int no=0;
        for(auto x:mp){
            if(x.second==maxf){
                no+=maxf;
            }
        }
        return no;

    }
};