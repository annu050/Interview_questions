class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int l;
        // l=nums.size();
        // sort(nums.begin(),nums.end());
        // return ((nums[l-1]-1)*(nums[l-2]-1));


        //2nd method
        int max1=INT_MIN;
        int max2=INT_MIN;
        for(int n:nums){
            if(n>max1){
                max2=max1;
                max1=n;
            }
            else if(n>max2){
                max2=n;
            }
        }
        return (max1-1)*(max2-1);
    }
};