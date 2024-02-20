class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(nums[n-1]==n-1){
            return n;
        }
        for(int i=0;i<nums.size();i++){
            if( i != nums[i]){
                return i;
            }
        }
        return -1;
    }
};