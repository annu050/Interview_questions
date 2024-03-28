class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        int l=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>k){
                while(nums[l]!=nums[i]){
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            } 
            ans=max(ans,i-l+1);       
        }
      return ans;  
    }
    
};