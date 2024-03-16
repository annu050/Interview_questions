class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp{{0,-1}};//sum,index
        int ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i]==1?1:-1;
            if(mp.count(sum)){
                ans=max(ans,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
        }
        return ans;
    }
};