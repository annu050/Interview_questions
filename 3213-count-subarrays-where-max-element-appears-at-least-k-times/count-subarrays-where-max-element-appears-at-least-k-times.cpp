class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        int l=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        long long c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                c++;
            }
            while(c>=k){
                if(nums[l]==maxi){
                    c--;
                }
                l++;
            }
            ans+=l;
        }
        return ans;
    }
};