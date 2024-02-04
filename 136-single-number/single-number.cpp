class Solution {
public:
    int singleNumber(vector<int>& nums) {
       //xor of 2 equal no. gives 0 and 0 xor no.=no.
       int ans=0;
       for(int i=0;i<nums.size();i++){
            ans=ans^nums[i];
       }
       return ans;
    }
};