class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        int l=k,r=k;
        int mini=nums[k];
        int prod=mini;
        while(l>0 || r<n-1){
            if(l==0 || (r<n-1 && nums[r+1]>nums[l-1])){
                r++;
            }
            else{
                l--;
            }
            mini=min(mini,min(nums[l],nums[r]));
            prod=max(prod,(mini*(r-l+1)));
        }
        return prod;
    }
};