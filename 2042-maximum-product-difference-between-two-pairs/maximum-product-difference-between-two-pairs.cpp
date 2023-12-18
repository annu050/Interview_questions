class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int l;
        l=nums.size();
        sort(nums.begin(),nums.end());
      
        return (nums[l-1]*nums[l-2])-(nums[0]*nums[1]);
        
        
    }
};