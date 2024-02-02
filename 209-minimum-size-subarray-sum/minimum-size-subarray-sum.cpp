class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,sum=0;
        int res=0;
        int ans_size=INT_MAX;
        for(int r=0;r<nums.size();r++){
            sum+=nums[r];
            while(sum>=target){
                ans_size=min(ans_size,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
       if(ans_size!=INT_MAX){
           return ans_size;
       }
       else{
           return 0;
       }
    }
};